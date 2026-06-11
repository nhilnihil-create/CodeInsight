#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll keta[62][2];
int main() {
	ll n;
	cin>>n;
	ll ch[300010];
	for(ll i=0;i<n;i++){
		cin>>ch[i];
	}
	for(ll i=0;i<n;i++){
		ll now=ch[i];
		ll j=0;
		while(j<62){
			keta[j][now%2]++;
			j++;
			now/=2;
		}
	}
	ll ans=0;
	ll k=1;
	for(ll i=0;i<62;i++){
		ll now=keta[i][0]*keta[i][1];
		now%=inf;
		ll cnt=k*now;
		cnt%=inf;
		ans+=cnt;
		ans%=inf;
		k*=2;
		k%=inf;
	}
	cout <<ans;
	// your code goes here
	return 0;
}