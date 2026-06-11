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

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n), f(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> f[i];
    sort(a.begin(), a.end());
    sort(f.begin(), f.end(), greater<ll>());
    ll l = -1, r = 1e12;
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        bool ok = [&](){
            ll s = 0;
            rep(i, n) {
                s += max(0ll, a[i] - mid / f[i]);
            }
            return s <= k;
        }();
        if (ok) r = mid; else l = mid;
    }

    cout << r << endl;

    return 0;
}