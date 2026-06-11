#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
#define FOR(i, a, n) for(ll i=(ll)a; i<(ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
template<typename T> void chmin(T &a, const T &b) { a = min(a, b); }
template<typename T> void chmax(T &a, const T &b) { a = max(a, b); }
struct FastIO {FastIO() { cin.tie(0); ios::sync_with_stdio(0); }}fastiofastio;
#ifdef DEBUG
#include "../program_contest_library/memo/dump.hpp"
#else
#define dump(...)
#endif
constexpr ll INF = 1LL<<60;

int main() {
    ll n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;

    vector<ll> dp(n+1);
    dp[n-1] = s[n-1] == 'o' ? 1 : 0;
    for(ll i=n-2; i>=0; --i) {
        dp[i] = dp[i+1];
        if(s[i]=='o') chmax(dp[i], 1LL);
        if(i+c+1<n && s[i]=='o') chmax(dp[i], dp[i+c+1]+1); 
    }
    dump(dp);

    ll last = -c-1, cnt = 0;
    REP(i, n) {
        if(s[i]=='x') continue;
        
        ll pos = max(i, last+c) + 1;
        ll tail = (pos<n ? dp[pos] : 0);
        dump(cnt, last, tail);
        if(cnt + tail < k) cout << i+1 << "\n";

        if(i-last>c) {
            cnt++;
            last = i;
        }
    }

    return 0;
}
