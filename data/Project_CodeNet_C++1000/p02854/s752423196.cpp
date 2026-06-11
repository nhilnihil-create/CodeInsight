#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> S(N + 1, 0);
    int A;
    for (int i = 1; i <= N; i++) {
        cin >> A;
        S[i] = S[i - 1] + A;
    }

    long long ans = S[N];
    for (int i = 1; i <= N; i++) {
        long long left = S[i];
        long long right = S[N] - left;
        ans = min(ans, abs(left - right));
    }

    cout << ans << endl;
}