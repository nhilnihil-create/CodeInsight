#include <bits/stdc++.h>
using namespace std;
#include<algorithm>
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
ll gcd(ll a,ll b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
int main() {
	ll n,m;
	cin>>n>>m;
	ll ch[100010];
	for(ll i=0;i<n;i++){
		cin>>ch[i];
		ch[i]/=2;
	}
	ll cnt=0;
	for(ll i=0;i<n;i++){
		ll now=0;
		while(ch[i]%2==0){
			now++;
			ch[i]/=2;
		}
		if(i==0){
			cnt=now;
			continue;
		}
		if(now!=cnt){
			cout << 0;
			return 0;
		}
	}
	while(cnt!=0){
		cnt--;
		m/=2;
	}
	ll lcm=ch[0];
	for(ll i=1;i<n;i++){
		ll now=gcd(max(lcm,ch[i]),min(lcm,ch[i]));
		//cout << now<<endl;
		//cout << lcm<<endl;
		//cout << ch[i]<<endl;
		now=lcm/now*ch[i];
		if(now>m){
			cout << 0;
			return 0;
		}
		lcm=now;
	}
	cout << (m+lcm)/(2*lcm);
	// your code goes here
	return 0;
}
