#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define repr(i, n) REPR(i, n, 0)
#define REPR(i, s, e) for(int i=(int)(s-1); i>=(int)(e); i--)
#define pb push_back
#define all(r) r.begin(),r.end()
#define rall(r) r.rbegin(),r.rend()
#define fi first
#define se second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1e9;
const ll MOD = 1e9 + 7;
double EPS = 1e-8;

map<ll, ll> calc(vector<ll>& s) {
    map<ll, ll> ret;
    rep(i, s.size()-1) {
        s[i+1] += s[i];
    }
    rep(i, s.size()) {
        rep(j, i) {
            ret[s[i]-s[j]]++;
        }
    }
    return ret;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        vector<ll> s[2];
        s[0].assign(n+1, 0LL);
        s[1].assign(m+1, 0LL);
        rep(i, n) {
            cin >> s[0][i + 1];
        }
        rep(i, m) {
            cin >> s[1][i + 1];
        }
        auto x = calc(s[0]), y = calc(s[1]);
        ll ans = 0LL;
        for(auto& p : x) {
            ans += p.se * y[p.fi];
        }
        cout << ans << endl;
    }
    return 0;
}
