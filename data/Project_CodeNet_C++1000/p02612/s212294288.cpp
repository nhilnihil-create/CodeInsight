#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll> 

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	ll n;
	cin>>n;
	ll x=n/1000;
	x++;
	ll ans=(x*1000)-n;
	cout<<ans%1000<<endl;
}
