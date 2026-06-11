#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mp make_pair
#define inf 1000000007
using namespace std;
signed main(){
	int n;
	string s,lr;
	cin>>n>>s;
	if(s[0]=='W' || s[2*n-1]=='W'){
		cout<<0<<endl;
		return 0;
	}
	int cnt=0;
	lr.pb('R');
	for(int i=1;i<2*n;i++){
		if(s[i] == s[i-1]){
			lr.pb( 'L'+'R'-lr[i-1]);
		}
		else{
			lr.pb(lr[i-1]);
		}
	}
	//cout<<lr<<endl;
	if(lr[2*n-1]!='L'){
		cout<<0<<endl;
		return 0;
	}
	int lc=0,rc=0;
	for(int i=0;i<2*n;i++){
		if(lr[i]=='L')lc++;
		else rc++;
	}
	if(lc!=rc){
		cout<<0<<endl;
		return 0;
	}
	ll ans = 1;
	ll lcnt = 0;
	for(int i=0;i<2*n;i++){
		if(lr[i]=='R')lcnt++;
		else{
			ans *= lcnt;
			ans %= inf;
			lcnt--;
		}
	}
	for(int i=1;i<=n;i++){
		ans *= i;
		ans %= inf;
	}
	cout<<ans<<endl;
	return 0;
}