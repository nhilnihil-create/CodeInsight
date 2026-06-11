#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")




int main() {


    ll n,x,l; cin >> n;
    ll r;
    ll ans = n;
    vector<pair<ll,ll>> p(n);

    rep(i,n){
        cin >> x >> l;
        p[i].first = x-l;
        p[i].second = x+l;
    }

    sort(p.begin(),p.end());
    rep(i,p.size()){
        if(i == 0) r = p[0].second;
        else{
            if(r <= p[i].first){
                r = p[i].second;
            }else{
                r = min(r,p[i].second);
                ans --;
            }
        }
    }

    cout << ans;

    return 0;
}
