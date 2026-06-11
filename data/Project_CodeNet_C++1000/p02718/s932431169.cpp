#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

int main() {
	ll n,m;
	cin>>n>>m;
	ll ans=0;
	ll cnt=0;
	ll a[1020];
	for(ll i=0;i<n;i++){
		ll now;
		cin>>now;
		a[i]=now;
		cnt+=now;
	}
	ll cnt2=0;
	for(ll i=0;i<n;i++){
		ll ma=a[i];
	if(ma*4*m>=cnt){
		cnt2++;
	}
	}
	if(cnt2>=m){
		cout << "Yes";
	}
	else{
		cout << "No";
	}
	return 0;
}