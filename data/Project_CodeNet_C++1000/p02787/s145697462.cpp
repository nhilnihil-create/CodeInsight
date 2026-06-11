#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll h,m;
	cin>>h>>m;
	ll ch[30000];
	ll a[1010];
	ll b[1010];
	for(ll i=0;i<m;i++){
		cin>>a[i]>>b[i];
	}
	for(ll i=0;i<30000;i++){
		ch[i]=inf;
	}
	ch[0]=0;
	ll ans=inf;
	for(ll i=0;i<20000;i++){
		for(ll j=0;j<m;j++){
			ch[i+a[j]]=min(ch[i+a[j]],ch[i]+b[j]);
			if(i+a[j]>=h){
			ans=min(ans,ch[i+a[j]]);
			}
		}
	}
	cout << ans;
}