#include<bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define vv vector<ll>
#define pb push_back
#define rep(i,a,n) for(ll i=a;i<(long long)n;++i)
#define repr(i,n,a) for(ll i=n;i>(long long)a;--i)
#define fe(it,v) for(auto it:v)
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 1000001
using namespace std;

void solve(){
	float n,x,t;
	cin>>n>>x>>t;
	cout<<fixed<<int(ceil(n/x)*t);

}

int main()
{
	// ll t;
	// cin>>t;
	// while(t--){
		solve();
		cout<<endl;
// }/
return 0 ;
}
