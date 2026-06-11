#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF 1e18
#define INF 1e9
#define MOD (ll)(1e9+7)
using namespace std;

#define fs first
#define sc second

using P = pair<ll,ll>;
using Pll = pair<P,ll>;
using PQ = priority_queue<P,vector<P>,greater<P>>;


signed main(){
    ll h1,h2,m1,m2,k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    ll d = h2*60+m2 - (h1*60+m1) - k;
    cout << d << endl;    
    return 0;

    
}
