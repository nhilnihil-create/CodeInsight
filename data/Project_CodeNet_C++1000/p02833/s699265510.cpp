#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;

int main(){
	ll n;cin>>n;
	if(n&1){cout<<0<<endl;}
	else{
		ll f=0;
		ll now=1;
		while(now<=n){
			now*=5;
			f+=(n/(now*2));
		}
		cout<<f<<endl;
	}
}
