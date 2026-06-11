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
	x = abs(x);
	if(k < (x/d)) cout<<x-k*d;
	else{
		int reqMoves = x/d+1;
		x = x - reqMoves*d;
		k = k - reqMoves;
		if(k%2==0)cout<<abs(x)<<endl;
		else cout<<x+d<<endl;
	}
}
	
signed main(){
    fast;    
    // int t;cin>>t;while(t--)
    solve();    
    return 0;
}
