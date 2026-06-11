#include <bits/stdc++.h>
using namespace std;

long A, B, C, D;

int main(void) {

    cin >> A >> B >> C >> D;

    while (A > 0 && C > 0) {
        A -= D;
        C -= B;
    }

    if (C <= 0) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }


    return 0;

}