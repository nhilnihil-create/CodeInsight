#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
#define chmin(a,b) a=min(a,b)
#define chmax(a,b) a=max(a,b)
#define rep(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
#define mad(a,b) a=(a+b)%mod
#define N 5010
ll K,D[N];
void solve(){
	ll n,m,x;
	cin>>n>>x>>m; n--;
	ll d[N];
	rep(i,K)d[i]=D[i]%m;
	ll vl=x/m;
	ll dsum=0; rep(i,K)dsum+=d[i];
	ll pnt=x+dsum*(n/K);
	rep(i,n%K)pnt+=d[i];
	ll vr=pnt/m;
	//cout<<"#"<<vl<<" "<<vr<<" "<<pnt<<endl;
	//cout<<"D=";rep(i,K)cout<<d[i]<<" "; cout<<endl;
	ll ans=n-(vr-vl);
	rep(i,K)if(d[i]==0)ans-=(n/K+(i<n%K));
	cout<<ans<<endl;
}
int main(){
	ll Q;
	cin>>K>>Q;
	rep(i,K)cin>>D[i];
	while(Q--)solve();
}


