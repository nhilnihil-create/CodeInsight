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
	ll ch[100010];	ll cnt2[100010];
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		x/=2;
		ll sum=0;
		while(x%2==0){
			sum++;
			x/=2;
		}		cnt2[i]=sum;
		ch[i]=x;
	}
	ll sum2=cnt2[0];
	for(ll i=0;i<n-1;i++){
		if(cnt2[i]!=cnt2[i+1]){
			cout << 0;
			return 0;
		}
		sum2=max(sum2,cnt2[i+1]);
	}
	for(ll i=0;i<sum2;i++){
		m/=2;
	}
	ll lcm=ch[0];
	for(ll i=0;i<n;i++){
		ll now=ch[i];
		ll gcd=dep(max(lcm,now),min(lcm,now));
		lcm=lcm/gcd*now;
		if(lcm>m){
			cout << 0;
			return 0;
		}
	}

//	cout << gcd<<endl;
//	cout << GCD<<endl;

	cout <<(m/lcm-1)/2+1;
	// your code goes here
	return 0;
}