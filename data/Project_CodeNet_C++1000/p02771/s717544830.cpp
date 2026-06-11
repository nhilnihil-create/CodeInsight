#include <bits/stdc++.h>
using namespace std;

// A - Poor
int main() {
    int A, B, C;
    cin >> A >> B >> C;
    if (A == B && A != C) {
        cout << "Yes";
        return 0;
    }
    if (A == C && A != B) {
        cout << "Yes";
        return 0;
    }
    if (B == C && B != A) {
        cout << "Yes";
        return 0;
    }
    cout << "No";
}
