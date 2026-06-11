#include <bits/stdc++.h>

#define ll long long
#define sz(x) (int)x.size();

using namespace std;

ll n;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	ll x=0;
	ll ans=0;
	while(n){
		ans+=pow(2ll,x);
		x++;
		n/=2;
	}
	cout<<ans;
	
}