#include <iostream>

int main(int argc, const char * argv[]) {
    int m, f, r;
    char grade;
    for ( ; std::cin >> m >> f >> r && !(m == -1 && f == -1 && r == -1); ) {
        if (m == -1 || f == -1) {
            grade = 'F';
        } else if (m + f >= 80) {
            grade = 'A';
        } else if (m + f >= 65) {
            grade = 'B';
        } else if (m + f >= 50) {
            grade = 'C';
        } else if (m + f >= 30) {
            if (r >= 50) {
                grade = 'C';
            } else {
                grade = 'D';
            }
        } else {
            grade = 'F';
        }
        std::cout << grade << std::endl;
    }
    return 0;
}