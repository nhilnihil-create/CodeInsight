#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll fac(ll n){
	ll res=0;
	for(ll i=1;i<=(ll)sqrt(n);++i){
		if(n%i==0){
			if(n/i==i) ++res;
			else res+=2;
		}
	}
	return res;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	ll count=0;
	vector<ll>v(n+1,1);
	for(ll i=2;i<=n;++i){
		for(ll j=1;j<=n/i;++j) v[j*i]++;
	}
	for(ll i=1;i<=n;++i) count+=(i*v[i]);
	cout<<count;
	return 0;
}