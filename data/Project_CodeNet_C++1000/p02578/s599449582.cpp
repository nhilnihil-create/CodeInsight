#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int N, A0, A;
    long long int ans = 0;

    cin >> N;
    cin >> A0;
    for (int i = 1; i < N; ++i) {
        cin >> A;
        if ((A - A0) < 0) {
            ans += A0-A;
            A = A0;
        }

        A0 = A;
    }
    cout << ans << endl;
}