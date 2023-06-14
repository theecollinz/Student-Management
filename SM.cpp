#include <iostream>
#include <vector>
using namespace std;

struct student {
    string firstName;
    string secondName;
    long long int registrationNum;
    string status;
    int subject1;
    int subject2;
    int subject3;
    int subject4;
    int subject5;
};

const int numofstudents = 2;
vector<student> students(numofstudents);

void viewstudents() {
    cout << "The number of students available are: " << students.size() << endl;
}

void viewstudentsinfo() {
    for (int i = 0; i < students.size(); i++) {
        cout << "Student " << i + 1 << " Information:" << endl;
        cout << "First name: " << students[i].firstName << endl;
        cout << "Second name: " << students[i].secondName << endl;
        cout << "Registration Number: " << students[i].registrationNum << endl;
        cout << "Status: " << students[i].status << endl;
        cout << endl;
    }
}

void updateStudentStatus(int studentIndex) {
    int subjectsAbove50 = 0;
    if (students[studentIndex].subject1 >= 50) {
        subjectsAbove50++;
    }
    if (students[studentIndex].subject2 >= 50) {
        subjectsAbove50++;
    }
    if (students[studentIndex].subject3 >= 50) {
        subjectsAbove50++;
    }
    if (students[studentIndex].subject4 >= 50) {
        subjectsAbove50++;
    }
    if (students[studentIndex].subject5 >= 50) {
        subjectsAbove50++;
    }

    if (subjectsAbove50 == 5) {
        students[studentIndex].status = "Pass";
    } else if (subjectsAbove50 >= 3) {
        students[studentIndex].status = "Retake";
    } else {
        students[studentIndex].status = "Supplementary";
    }
}

void updatestudentinfo() {
    int studentindex;
    cout << "Enter the index of the student to update: ";
    cin >> studentindex;
    if (studentindex < 1 || studentindex > students.size()) {
        cout << "Invalid index." << endl;
        return;
    }
    cout << "First name: ";
    cin >> students[studentindex - 1].firstName;
    cout << "Second name: ";
    cin >> students[studentindex - 1].secondName;
    cout << "Registration number: ";
    cin >> students[studentindex - 1].registrationNum;
    cout << "Student " << studentindex << " information updated." << endl;
}

void addstudentresults() {
    for (int i = 0; i < students.size(); i++) {
        cout << "Enter results for student " << i + 1 << ":" << endl;
        cout << "Subject 1: ";
        cin >> students[i].subject1;
        cout << "Subject 2: ";
        cin >> students[i].subject2;
        cout << "Subject 3: ";
        cin >> students[i].subject3;
        cout << "Subject 4: ";
        cin >> students[i].subject4;
        cout << "Subject 5: ";
        cin >> students[i].subject5;
        updateStudentStatus(i);
        cout << endl;
    }
}

void viewstudentresults() {
    for (int i = 0; i < students.size(); i++) {
        cout << "Results of student " << i + 1 << ":" << endl;
        cout << "Subject 1: " << students[i].subject1 << endl;
        cout << "Subject 2: " << students[i].subject2 << endl;
        cout << "Subject 3: " << students[i].subject3 << endl;
        cout << "Subject 4: " << students[i].subject4 << endl;
        cout << "Subject 5: " << students[i].subject5 << endl;
        cout << endl;
    }
}

void updatestudentresults() {
    int studentindex;
    cout << "Enter the index of the student to update: ";
    cin >> studentindex;
    if (studentindex < 1 || studentindex > students.size()) {
        cout << "Invalid index." << endl;
        return;
    }
    cout << "Enter new results for student " << studentindex << ":" << endl;
    cout << "Subject 1: ";
    cin >> students[studentindex - 1].subject1;
    cout << "Subject 2: ";
    cin >> students[studentindex - 1].subject2;
    cout << "Subject 3: ";
    cin >> students[studentindex - 1].subject3;
    cout << "Subject 4: ";
    cin >> students[studentindex - 1].subject4;
    cout << "Subject 5: ";
    cin >> students[studentindex - 1].subject5;
    updateStudentStatus(studentindex - 1);
    cout << "Results updated for student " << studentindex << endl;
}

int main() {
    int choices;

    for (int i = 0; i < numofstudents; i++) {
        cout << "____________________________________________________________" << endl;
        cout << "Enter information of student " << i + 1 << ":" << endl;
        cout << "Enter firstname of student: ";
        cin >> students[i].firstName;
        cout << "Enter secondname of student: ";
        cin >> students[i].secondName;
        cout << "Enter registration number of student: ";
        cin >> students[i].registrationNum;
        cout << "____________________________________________________________" << endl;
        cout << endl
             << endl;
    }

    while (true) {
        cout << "1. View students." << endl;
        cout << "2. View students information." << endl;
        cout << "3. Update student information." << endl;
        cout << "4. Add student results." << endl;
        cout << "5. View student results." << endl;
        cout << "6. Update student results." << endl;
        cout << "7. Exit Program." << endl;
        cout << "\n\n\tSelect choice: ";
        cin >> choices;
        switch (choices) {
            case 1:
                viewstudents();
                break;
            case 2:
                viewstudentsinfo();
                break;
            case 3:
                updatestudentinfo();
                break;
            case 4:
                addstudentresults();
                break;
            case 5:
                viewstudentresults();
                break;
            case 6:
                updatestudentresults();
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }

    return 0;
}
