#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	// your code goes here
	const int N = 1e6;
	vector <ll> div(N+1,0);
	for(int i=1;i<=N;i++){
		for(int j=1;i*j<=N;j++){
			div[i*j]++;
		}
	}
	ll n;
	cin>>n;
	ll ans = 0;
	for(ll c = 1;c<=n-1;c++){
		ll rem = n - c;
		ans += div[rem];
	}
	cout<<ans<<"\n";
	return 0;
}