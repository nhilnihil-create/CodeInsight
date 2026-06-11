#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,m,a[1005],b[1005],p[13];
	ll cnt=1;
	for(ll i=0;i<13;i++){
		p[i]=cnt;
		cnt*=2;
	}
	cin>>n>>m;
	for(ll i=0;i<m;i++){
		ll x,y;
		cin>>x>>y;
		a[i]=x;
		ll now=0;
		for(ll j=0;j<y;j++){
			ll next;
			cin>>next;
			next--;
			now=now|p[next];
		}
		b[i]=now;
//		cout <<now<<endl;
	}
	ll dp[100000];
	for(ll i=0;i<100000;i++){
		dp[i]=INF;
	}
	dp[0]=0;
	for(ll i=0;i<100000;i++){
		for(ll j=0;j<m;j++){
			ll cost=a[j];
			ll op=b[j];
			ll next=i|op;
			if(next<100000){
			dp[next]=min(dp[next],dp[i]+cost);
			}
		}
	}
//	cout << ll(pow(2,n))-1;
	if(dp[ll(pow(2,n))-1]==INF){
		cout <<-1;
		return 0;
	}
	cout <<dp[ll(pow(2,n))-1];
	// your code goes here
	return 0;
}