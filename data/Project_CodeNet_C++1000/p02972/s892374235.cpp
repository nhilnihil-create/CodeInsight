#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define P pair<ll, ll>
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

////////////////////////////////////////////////////////


int main() {
    ll n; cin >> n;
    Vl a(n+1), ans(n+1, 0);
    Rep(i, 1, n) cin >> a[i];
    for(int i = n; i >= 1; i--){
        if(i > n/2) ans[i] = a[i];
        else{
            ll t = 2*i;
            ll cnt = 0;
            while(t <= n){
                if(ans[t]) cnt++;
                cnt %= 2;
                t += i;
            }
            ans[i] = (cnt+a[i])%2;
        }
    }
    ll nu = 0;
    Rep(i, 1, n){
        if(ans[i]) nu++;
    }
    co(nu);
    Rep(i, 1, n){
        if(ans[i]) cout << i << " ";
    }
    if(!nu) coel;
    

    return 0;
}
