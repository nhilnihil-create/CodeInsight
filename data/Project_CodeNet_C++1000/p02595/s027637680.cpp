#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fast ios::sync_with_stdio(false); cin.tie(NULL);
#define loop(n) for(int i=0; i<n; i++)
#define loopo(i,n) for(int i=0; i<n; i++)
const int INF = 2e18;

void solve(){
	int n;cin>>n;
	int d;cin>>d;

	int ans = 0;
	loop(n){
		int x,y;cin>>x>>y;
		double b = (double)sqrt( x*x + y*y );
		if(b<=(double)d)ans++;
	}
	cout<<ans<<endl;



}
	
signed main(){
    fast;    
    // int t;cin>>t;while(t--)
    solve();    
    return 0;
}