#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define chmin(a,b) a=min(a,b)
#define chmax(a,b) a=max(a,b)
#define N 100010
ll n,a[N],b[N],s[N];
int main(){
	cin>>n;
	for(int i=0;i<=n;i++)cin>>a[i];
	if(n==0){
		if(a[0]==1)cout<<1<<endl;
		else cout<<-1<<endl;
		return 0;
	}
	if(a[0]>0){
		cout<<-1<<endl;
		return 0;
	}
	s[n+1]=0;
	for(int i=n;i>=0;i--){
		s[i]=s[i+1]+a[i];
	}
	b[0]=1;
	for(int i=1;i<=n;i++){
		b[i]=2*b[i-1]-a[i];
		chmin(b[i],s[i+1]);
		if(b[i]<0||a[i]+b[i]<b[i-1]){
			cout<<-1<<endl;
			return 0;
		}
	}
	ll ans=0;
	for(int i=0;i<=n;i++){
		ans+=a[i]+b[i];
	}
	cout<<ans<<endl;
}
