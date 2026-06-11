#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fast ios::sync_with_stdio(false); cin.tie(NULL);
#define rep(n) for(int i=0; i<n; i++)
#define rep1(i,n) for(int i=0; i<n; i++)
const int INF = 2e18;

void solve(){
	
	int x,k,d;cin>>x>>k>>d;
	// cout<<fixed<<setprecision(12);
	x = abs(x);
	if(k < (x/d)) cout<<x-k*d;
    else{
        k -= (x/d);
        x -= (x/d)*d;
        if(k%2) cout<<d-x;
        else cout<<x;
    }
}
	
signed main(){
    fast;    
    // int t;cin>>t;while(t--)
    solve();    
    return 0;
}