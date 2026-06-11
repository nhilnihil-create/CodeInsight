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

int main(){
	ll x,y;
	cin>>x>>y;
	ll ans=0;
	if(x<=3)ans+=400000-x*100000;
	if(y<=3)ans+=400000-y*100000;
	if(x==1&&y==1)ans+=400000;
	cout<<ans<<endl;
}
