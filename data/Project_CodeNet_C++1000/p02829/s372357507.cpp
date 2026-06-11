#include <bits/stdc++.h>
using namespace std;

// 
int main() {
    int A, B;
    cin >> A >> B;

    if (A == 1 && B == 2 || A == 2 && B == 1 ) {
        cout << 3;
        return 0;
    }
    if (A == 1 && B == 3 || A == 3 && B == 1 ) {
        cout << 2;
        return 0;
    }
    if (A == 2 && B == 3 || A == 3 && B == 2 ) {
        cout << 1;
        return 0;
    }
}
