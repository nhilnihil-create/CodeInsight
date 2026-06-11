#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const ll N=5e5+1;
const ll INF=1e10;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	ll sum=0,n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		ll x=n/i;
		sum+=(x)*(x+1)/2*i;
	}
	cout<<sum;
}
