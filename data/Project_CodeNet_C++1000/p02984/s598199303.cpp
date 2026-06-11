#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,a[100010];
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	ll cnt=0;
	for(ll i=0;i<n;i++){
		cnt*=-1;
		cnt+=a[i];
	}
	ll ans=cnt/2;
	cout << ans*2<<" ";
	for(ll i=0;i<n-1;i++){
		ans*=-1;
		ans+=a[i];
		cout << 2*ans<<" ";
	}
	// your code goes here
	return 0;
}