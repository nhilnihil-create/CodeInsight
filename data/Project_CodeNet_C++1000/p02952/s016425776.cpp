#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,ans=0;
	cin>>n;
	for(ll i=1;i<=n;i++){
		ll now=i;
		ll cnt=0;
		while(now!=0){
			now/=10;
			cnt++;
		}
		if(cnt%2!=0){
			ans++;
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}