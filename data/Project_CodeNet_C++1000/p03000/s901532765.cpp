#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF 1e18
#define INF 1e9
using namespace std;

#define fs first
#define sc second

using P = pair<ll,ll>;
using Pll = pair<P,ll>;
using PQ = priority_queue<P,vector<P>,greater<P>>;

signed main(){
    ll n,x;
    cin >> n >> x;
    ll l[n] = {};
    ll cnt = 1,pos = 0;
    rep(i,0,n){
        cin >> l[i];
        if(pos+l[i] <= x){
            cnt++;
            pos += l[i];
        }
        else{
            break;
        }
    }
    cout << cnt << endl;
    return 0;
}
