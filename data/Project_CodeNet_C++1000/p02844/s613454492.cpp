#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	string s;
	cin>>s;
	ll ans=0;
	for(ll i=0;i<=999;i++){
		ll now=i;
		ll ch2[3];
		for(ll j=0;j<3;j++){
			ch2[j]=now%10;
			now/=10;
		}
		ll cnt=0;
		for(ll j=0;j<n;j++){
			if(ll(s[j]-'0')==ch2[cnt]){
				cnt++;
			}
			if(cnt==3){
				ans++;
				break;
			}
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}