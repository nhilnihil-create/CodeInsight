#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll ans[101];
int main() {
	ll n;
	cin>>n;
	ll b[101];
	for(ll i=0;i<n-1;i++){
		cin>>b[i];
	}
	ans[0]=b[0];
	ans[n-1]=b[n-2];
	for(ll i=1;i<n-1;i++){
		ans[i]=min(b[i],b[i-1]);
	}
	ll sum=0;
	for(ll i=0;i<n;i++){
		sum+=ans[i];
	}
	cout <<sum;
	// your code goes here
	return 0;
}