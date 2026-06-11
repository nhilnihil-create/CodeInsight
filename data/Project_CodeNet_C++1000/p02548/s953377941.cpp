#include <bits/stdc++.h>
using namespace std;  
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define Rep(i, a, b) for(ll i = a; i <= b; i++)
#define repr(i, a, b) for(ll i = b-1; i >= a; i--)
// #define _GLIBCXX_DEBUG
template <class T> using V = vector<T>;
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
const double pi = acos(-1.0);
const ll MOD = 1000000007LL;
const ll INF = 1LL << 60;
#define pp pair<ll, pair<ll, ll>> 
// #define fi first
// #define se second
// ios::sync_with_stdio(false);
// cin.tie(nullptr);
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

/*--------------------------------------------------------------------------------

--------------------------------------------------------------------------------*/

int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    rep(a, 1, n){
        ans += (n-1)/a;
    }
    cout << ans << endl;

    return 0;
}