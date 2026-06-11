#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define F first
#define S second
#define mod 1000000007
#define all(a) a.begin(),a.end()
#define dbg(n) cout<<#n<<' '<<n<<endl;
#define dbg_v(v) cout<<#v<<":";for(auto c:v) cout<<" "<<c; cout<<endl;
int power(ll x,ll y){ll res = 1;while(y>0){if(y&1)res = (res*x)%mod;y=y>>1;x=(x*x)%mod;}return res;}
void solve(){
	ll h;
	cin>>h;
	int res=(double)log2(h);
	//cout<<res<<endl;
	ll p=1,ans=0;
	ans=(ll)pow(2,res+1)-1;
	cout<<ans<<endl;
}
int main(){ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	}
}
