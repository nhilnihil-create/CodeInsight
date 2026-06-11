#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;

using ll = long long;
using ld = long double;
const int INF = 1e9+100;
const ll INF64 = 7e18l;
const int mod = 1000000007;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(a) (a).begin(), (a).end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main(){
    FIN;
    ll n,q;
    cin >> n >> q;
    dsu d(n);
    for(ll i=0;i<q;i++){
        ll t,u,v;
        cin >> t >> u >> v;
        if(t == 0) d.merge(u,v);
        else cout << d.same(u,v) << endl;
    }

    return 0;
}