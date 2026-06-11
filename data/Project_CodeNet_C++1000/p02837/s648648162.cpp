#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

ll n;
vector<vector<P>> v;

bool check(ll bit){
    rep(i,n){
        if(!(bit & (1<<i))) continue;
        for(auto xy:v[i]){
            ll x = xy.first, y = xy.second;
            if(y==1 && !(bit & (1<<x))) return false;
            if(y==0 && (bit & (1<<x))) return false;
        }
    }
    return true;
}

int main(void)
{
    cin >> n;
    v.resize(n);
    rep(i,n){
        ll a;
        cin >> a;
        rep(j,a){
            ll x, y;
            cin >> x >> y;
            x--;
            v[i].push_back({x,y});
        }
    }
    ll ans = 0;
    rep(bit,(1<<n)){
        if(check(bit)){
            ll cnt = 0;
            rep(i,n){
                if(bit & (1<<i)) cnt++;
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
    return 0;
}