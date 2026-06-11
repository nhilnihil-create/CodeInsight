#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n, a, b; 
	cin>>n>>a>>b;
	if(a==0)cout<<0<<endl;
	else if(n%(a+b) == 0){
		ll op = n/(a+b);
		cout<<1ll*a*op<<endl;
	}
	else{
		ll x = n/(a+b), y = n%(a+b);
		ll rta = a*x;
		rta+=min(y, a);
		cout<<rta<<endl;
	}
}

