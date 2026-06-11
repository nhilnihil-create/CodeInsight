#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
	ll ch[62][2];
int main() {
	ll n;
	cin>>n;
	ll a[300010];
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	for(ll i=0;i<n;i++){
		ll now=a[i];
		ll j=0;
		while(j<=61){
			ch[j][now%2]++;
			now/=2;
			j++;
		}
	}
	ll keta=1;
	ll ans=0;
	for(ll i=0;i<=61;i++){
		ll now=ch[i][0]*ch[i][1];
	//	cout << ch[i][0]<<ch[i][1]<<endl;
		now%=inf;
		now*=keta;
		now%=inf;
		ans+=now;
		ans%=inf;
		keta*=2;
		keta%=inf;
	}
	cout <<ans;
	// your code goes here
	return 0;
}