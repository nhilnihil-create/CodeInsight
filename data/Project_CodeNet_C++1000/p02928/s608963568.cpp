#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 61;
const int NIL = -1;
const int MAX = 10000;
const int MOD = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    ll N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int &ai : a) cin >> ai;

    // ... ai-1 , ai, ai+1, ...
    // 1回目はai+1~だけ
    // 2回目以降は全て
    vector<ll> cnt_before(N), cnt_after(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) cnt_before[i]++;
        }
        for (int j = i + 1; j < N; j++) {
            if (a[j] < a[i]) cnt_after[i]++;
        }
    }
    ll ans = 0;
    ll before = ((K - 1) * K / 2) % MOD;
    ll after = (K * (K + 1) / 2) % MOD;
    for (int i = 0; i < N; i++) {
        ans += before * cnt_before[i];
        ans %= MOD;
        ans += after * cnt_after[i];
        ans %= MOD;
    }
    cout << ans << '\n';
}
