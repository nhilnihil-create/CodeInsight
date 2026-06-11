#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
	ll ch[62][2];
int main() {
	ll n;cin>>n;
	for(ll i=0;i<62;i++){
		ch[i][0]=n;
	}
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		ll now=0;
		while(x!=0){
			if(x%2==1){
				ch[now][1]++;
				ch[now][0]--;
			}
			now++;
			x/=2;
		}
	}
	ll now=1;
	ll ans=0;
	for(ll i=0;i<62;i++){
		ll cn=ch[i][0]*ch[i][1];
		cn%=inf;
		cn*=now;
		cn%=inf;
		ans+=cn;
		ans%=inf;
		now*=2;
		now%=inf;
	}
	cout <<ans;
	return 0;
}