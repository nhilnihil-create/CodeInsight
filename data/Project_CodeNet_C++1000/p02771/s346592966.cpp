#include <bits/stdc++.h>

using namespace std;

int main() {
    int A = 0, B = 0, C = 0;
    cin >> A >> B >> C;

    if (A == B && B != C) {
        cout << "Yes" << endl;
        return 0;
    } else if (B == C && C != A) {
        cout << "Yes" << endl;
        return 0;
    } else if (A == C && C != B) {
        cout << "Yes" << endl;
        return 0;
    } else {
        cout << "No" << endl;
        return 0;
    }
}