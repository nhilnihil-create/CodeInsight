#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll cnt[2100];
ll gya(ll n,ll p, ll m){
	ll b=1;
	while(p){
		if(p%2)b=(b*n)%m;
		n=(n*n)%m;
		p/=2;
	}
	return b;
}
int main(){
	string s;
	cin>>s;
	ll now=0;
	for(int i=s.size()-1;i>=0;i--){
		now+=gya(10,s.size()-i-1,2019)*(s[i]-'0');
		now%=2019;
		cnt[now]++;
	}
	cnt[0]++;
	ll ans=0;
	for(int i=0;i<2019;i++){
		ans+=cnt[i]*(cnt[i]-1)/2;
		//cout<<cnt[i]<<' ';
	}
	cout<<ans;
	return 0;
}
