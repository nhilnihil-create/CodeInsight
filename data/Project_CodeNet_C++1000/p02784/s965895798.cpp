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
	int h,n;
	cin>>h>>n;
	ll sum=0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		sum+=x;
	}
	if(sum>=h)
		cout<<"Yes\n";
	else
		cout<<"No\n";
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
