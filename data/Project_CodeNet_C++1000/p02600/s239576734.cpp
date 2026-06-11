#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define pp pair<ll, pair<ll, ll>> 
#define fi first
#define se second

////////////////////////////////////////////////////////


int main() {
    ll x; cin >> x;
    ll ans;
    if(x < 600) ans = 8;
    else if(x < 800) ans = 7;
    else if(x < 1000) ans = 6;
    else if(x < 1200) ans = 5;
    else if(x < 1400) ans = 4;
    else if(x < 1600) ans = 3;
    else if(x < 1800) ans = 2;
    else if(x < 2000) ans = 1;

    co(ans);

    return 0;
}


