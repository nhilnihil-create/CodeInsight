#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
int main() {
	ll h,m;
	cin>>h>>m;
	ll a[10010],b[10010];
	ll ch[20010]={};
	for(ll i=1;i<20010;i++){
		ch[i]=INF;
	}
	for(ll i=0;i<m;i++){
		cin>>a[i]>>b[i];
	}
	ll ans=INF;
	for(ll i=0;i<h;i++){
		for(ll j=0;j<m;j++){
			ll nexa=a[j];
			ll nexb=b[j];
			ch[i+nexa]=min(ch[i+nexa],ch[i]+nexb);
			if(i+nexa>=h){
				ans=min(ans,ch[i+nexa]);
			}
		}
	}
	cout <<ans;
	return 0;
}