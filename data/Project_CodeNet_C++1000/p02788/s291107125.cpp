#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

static const ll maxx = 1e9;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n, d, a;
    cin >> n >> d >> a;
    vector<pair<ll, ll>> m(n);
    rep(i, n) {
        cin >> m[i].first >> m[i].second;
    }

    sort(m.begin(), m.end());
    d = d * 2;
    ll tot = 0;
    queue<pair<ll, ll>> q;
    ll ans = 0;
    
    rep(i, n) {
        ll x = m[i].first;
        ll h = m[i].second;
        while(q.size() && q.front().first < x) {
            tot -= q.front().second;
            q.pop();
        }
        h -= tot;
        if (h > 0) {
            ll num = (h + a - 1) / a;
            ans += num;
            ll damage = num * a;
            tot += damage;
            q.emplace(x + d, damage);
        }
    }

    cout << ans << endl;

    return 0;
}