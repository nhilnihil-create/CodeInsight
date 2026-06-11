#include <bits/stdc++.h>
using namespace std;

long X, A, B;

int main(void) {

    cin >> X;

    for (A = -1000; A <= 1000; A++) {
        for (B = -1000; B <= 1000; B++) {
            if (A*A*A*A*A - B*B*B*B*B == X) {
                cout << A << " " << B << endl;
                return 0;
            }
        }
    }


    return 0;

}