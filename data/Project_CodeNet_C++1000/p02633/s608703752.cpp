#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define mod 1000000007
#define PI 3.141592653589793238
#define all(a) a.begin(),a.end()
#define dbg(n) cout<<#n<<' '<<n<<endl;
#define dbg_v(v) cout<<#v<<":";for(int i=0;i<(int)v.size();i++) cout<<" "<<v[i]; cout<<endl;
ll power(ll x,ll y){ll res = 1;while(y>0){if(y&1)res = (res*x)%mod;y=y>>1;x=(x*x)%mod;}return res;}
void solve(){
	int x;
	cin>>x;
	if(360%x==0)
		cout<<360/x<<endl;
	else{
		int k=__gcd(x,360);
		cout<<360/k<<endl;
	}
		
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	int T=1;
	//cin>>T;
	while(T--)
		solve();
}
