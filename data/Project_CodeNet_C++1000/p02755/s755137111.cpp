#include <bits/stdc++.h>
using namespace std;

// C - Tax Increase
int main() {
    int A, B;
    cin >> A >> B;

    int X = B * 10;
    int result = -1;
    int tmp;
    for (int i = X; i <= X + 10; i++) {
        // cout << i << " : "; // debug
        tmp = i * 0.1;
        // cout << tmp << ", "; // debug
        if (tmp != B) break;
        tmp = i * 0.08;
        // cout << tmp << ", " << endl; // debug
        if (tmp == A) {
            result = i;
            break;
        }
    }
    cout << result;
}
