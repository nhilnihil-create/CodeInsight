#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll dep(ll a, ll b){
	if(b==0){
		return a;
	}
	return dep(b,a%b);
}
int main() {
	ll n;
	cin>>n;
	if(n%2!=0){
		cout << 0;
		return 0;
	}
	ll now=10;
	ll ans=0;
	while(now<=n){
		ans+=n/now;
		now*=5;
	}
	cout <<ans;
	return 0;
}