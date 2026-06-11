#include <iostream>
using namespace std;

int main() {
    bool students[31];
    for (int i = 1; i <= 30; i++) {
        students[i] = false;
    }
    for (int i = 0; i < 28; i++) {
        int index;
        cin >> index;
        students[index] = true;
    }
    for (int i = 1; i <= 30; i++) {
        if (students[i] == false) {
            cout << i << endl;
        }
    }
}