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
    ll n,k;
    string s;
    cin >> n >> k >> s;

    ll cnt = 1;
    rep(i,0,n-1){
        if(s[i] != s[i+1]) cnt++;
    }
    cout << (ll)min(n - max((cnt-2*k),0LL),n-1LL) << endl;
    return 0;
}
