#include <bits/stdc++.h>
using namespace std;

long A, B, C, K;

int main(void) {

    cin >> A >> B >> C >> K;

    if (K <= A) {
        cout << min(A, K) << endl;
    }
    else if (K <= A + B) {
        cout << A << endl;
    }
    else {
        cout << A - (K - A - B) << endl;
    }

    return 0;

}