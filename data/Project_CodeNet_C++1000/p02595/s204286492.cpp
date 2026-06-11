#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;

/* --------------------------------------------------- */

ll n, d, ans = 0;

void solve(ll p, ll q) {
    if(p * p + q * q <= d * d) ans++;
}

int main() {
    cin >> n >> d;
    rep(i, n) {
        ll x, y;
        cin >> x >> y;
        solve(x, y);
    }
    cout << ans << endl;

    return 0;
}