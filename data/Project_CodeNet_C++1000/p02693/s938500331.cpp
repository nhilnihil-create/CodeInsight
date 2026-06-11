#include<iostream>
using namespace std;

int main(void) {
    int K, A, B; cin >> K >> A >> B;
    bool isMultipleOfK = false;
    for (int i = A; i <= B; i++) {
        if (i % K == 0) {
            isMultipleOfK = true;
        }
    }
    if (isMultipleOfK) {
        cout << "OK" << endl;
    } else {
        cout << "NG" << endl;
    }
}
