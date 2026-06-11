#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
    ll N, K; cin >> N >> K;
    int cnt[2001] = {};
    vector<int> A(N);
    REP(i, 0, N) {
        cin >> A[i];
        cnt[A[i]]++;
    }

    int prev = 0; int less[2001] = {};
    REP(i, 0, 2001) {
        less[i] = prev;
        prev += cnt[i];
    }

    ll ans = 0;
    REP(i, 0, N) {
        int tmp = 0;
        REP(j, i + 1, N) {
            if (A[i] > A[j]) tmp++;
        }
        ans = (ans + (tmp * K) % MOD) % MOD;
        
        ans = (ans + (((K - 1) * K / 2) % MOD * less[A[i]]) % MOD) % MOD;
    }

    cout << ans << endl;
    return 0;
}