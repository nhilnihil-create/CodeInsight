#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,k;
	cin>>n>>k;
	long double ch[200010];
	for(ll i=0;i<n;i++){
		cin>>ch[i];
	}
	long double sum1=0;
	for(ll i=0;i<k;i++){
		long double now=(ch[i]+1)/2;
		sum1+=now;
	}
	long double ans=sum1;
	for(ll i=k;i<n;i++){
		sum1+=(ch[i]+1)/2-(ch[i-k]+1)/2;
		ans=max(sum1,ans);
	}
	printf("%.10Lf",ans);
	// your code goes here
	return 0;
}