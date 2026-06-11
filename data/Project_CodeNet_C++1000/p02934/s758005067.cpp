#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	long double ans=0;
	for(ll i=0;i<n;i++){
		long double now;
		cin>>now;
		now=1.0/now;
		ans+=now;
	}
	ans=1.0/ans;
	cout <<ans;
	return 0;
}