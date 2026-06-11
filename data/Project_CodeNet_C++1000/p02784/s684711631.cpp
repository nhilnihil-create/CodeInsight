#include <bits/stdc++.h>
using namespace std;

// B - Common Raccoon vs Monster
int main() {
    long long H, N;
    cin >> H >> N;
    long long A;
    for (long long i = 0; i < N; i++) {
        cin >> A;
        H -= A;
        if (H <= 0) {
            break;
        }
    }
    if (H <= 0) cout << "Yes";
    else cout << "No";
}
