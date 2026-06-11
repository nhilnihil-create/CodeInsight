#include <bits/stdc++.h>
using namespace std;
#include<algorithm>
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
ll dep(ll a,ll b){
	if(b==0){
		return a;
	}
	return dep(b,a%b);
}
int main() {
	ll n,m;
	cin>>n>>m;
	ll ch[100010];
	for(ll i=0;i<n;i++){
		ll now;cin>>now;
		now/=2;
		ch[i]=now;
	}
	ll ch2[100010]={};
	for(ll i=0;i<n;i++){
		ll now=ch[i];
		ll j=0;
		while(now%2==0){
			j++;
			now/=2;
		}
		ch2[i]=j;
		ch[i]=now;
	}
	for(ll i=0;i<n-1;i++){
		if(ch2[i]!=ch2[i+1]){
			cout <<0;
			return 0;
		}
	}
	ll cn=ch2[0];
	while(cn!=0){
		cn--;
		m/=2;
	}
	ll lcm=ch[0];
	for(ll i=1;i<n;i++){
		ll gcd=dep(max(lcm,ch[i]),min(lcm,ch[i]));
		lcm=lcm/gcd*ch[i];
		if(lcm>m){
			cout << 0;
			return 0;
		}
	}
	cout << (m/lcm-1)/2+1;
	// your code goes here
	return 0;
}