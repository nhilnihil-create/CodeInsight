#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
	ll ch2[3]={};
int main() {
	ll n;
	cin>>n;
	ll ch[100010];

	for(ll i=0;i<n;i++){
		cin>>ch[i];
	}
	ll ans=1;
	for(ll i=0;i<n;i++){
		ll cnt=0;
		ll now=ch[i];
		ll num=1;
		for(ll j=0;j<3;j++){
		 if(now==ch2[j]){
		 	ch2[j]+=num;
		 	num--;
		 	num=max(ll(0),num);
		 	cnt++;
		 }
		}
		ans*=cnt;
		ans%=inf;
	}
	cout<<ans;
	// your code goes here
	return 0;
}