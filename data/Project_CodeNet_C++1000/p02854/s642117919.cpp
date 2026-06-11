#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define chmin(a,b) a=min(a,b)
#define chmax(a,b) a=max(a,b)
#define all(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
#define mad(a,b) a=(a+b)%mod
ll n,a[200010];
int main(){
	cin>>n;
	ll sum=0;
	rep(i,n){
		cin>>a[i];
		sum+=a[i];
	}
	ll rui=0;
	ll ans=1e17;
	rep(i,n){
		rui+=a[i];
		ll x=sum-rui;
		ll y=rui;
		if(x<y)swap(x,y);
		chmin(ans,x-y);
	}
	cout<<ans<<endl;
}
