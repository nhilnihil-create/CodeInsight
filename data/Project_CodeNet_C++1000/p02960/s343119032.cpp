#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define modulo 1000000007
#define fast_io ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
using namespace std;
int main(){
	fast_io;
	string s;
	cin>>s;
	ll n=s.length();
	ll a[n][13];
	memset(a,0,sizeof(a));
	if(s[0]=='?'){
		for (int i = 0; i <= 9; ++i){
			a[0][i]=1;
		}
	}
	else
		a[0][(s[0]-'0')]++;
	for (int i = 1; i < n; ++i){
		vector<ll>v;
		if(s[i]!='?')
			v.pb((s[i]-'0'));
		else{
			v.pb(0);v.pb(1);v.pb(2);v.pb(3);v.pb(4);v.pb(5);v.pb(6);v.pb(7);v.pb(8);v.pb(9);
		}
		for (int j = 0; j < v.size(); ++j){
			ll x=v[j];
			for (int k = 0; k < 13; ++k){
				a[i][(x+k*10)%13]=(a[i-1][k]+a[i][(x+k*10)%13])%modulo;
			}
		}
	}
	cout<<a[n-1][5]<<"\n";
	return 0;
}