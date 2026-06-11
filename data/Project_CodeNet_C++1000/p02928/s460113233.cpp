
#include<bits/stdc++.h>
using namespace std;
int A[2010];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int MOD = 1e9 + 7;
    int n, k;;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        for (int j = i + 1; j <= n; ++j) {
            if (A[i] > A[j]) {
                ++cnt;
            }
        }
        int x = (1LL * k * (k + 1) / 2) % MOD;
        answer = (0LL + answer + (1LL * cnt * x) % MOD) % MOD;
        cnt = 0;
        //cout << answer << '\n';
        for (int j = 1; j < i; ++j) {
            if (A[i] > A[j]) {
                ++cnt;
            }
        }
        x = (1LL * (k - 1) * (k) / 2) % MOD;
        answer = (0LL + answer + (1LL * cnt * x) % MOD) % MOD;
        //cout << answer << '\n';
    }
    cout << answer;
}
