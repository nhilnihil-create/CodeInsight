#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	if(n%2==1){
		cout << 0;
		return 0;
	}
	ll ans1=0;
	ll ans2=0;
	ll cnt=5;
	while(cnt<=n){
		ans1+=n/cnt;
		if(n/cnt!=0){
			ll nex=n/cnt;
			ans2+=(nex+2-1)/2;
		}
		cnt*=5;
	}
	cout <<ans1-ans2;
	// your code goes here
	return 0;
}