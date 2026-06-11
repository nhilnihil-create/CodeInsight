#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n; 
int main(){
	cin>>n;
	if(n&1)cout<<0<<endl;
	else{
		ll sum=0,x=n;
		for(ll t=10;(x/t)!=0;t*=5)
			sum+=x/t;
		cout<<sum<<endl;
	}
	return 0;
}