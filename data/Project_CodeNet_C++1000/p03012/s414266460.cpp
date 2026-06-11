#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 
 
int main() {
	ll n;
	cin>>n;
	ll a[102];
	ll sum=0;
	for(ll i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	ll ans=inf;
	ll sum1=0;
	for(ll i=0;i<n-1;i++){
		sum1+=a[i];
		ans=min(ans,abs(sum-2*sum1));
	}
	cout <<ans;
	// your code goes here
	return 0;
}