#include <bits/stdc++.h>

using namespace std;
 
int main() {

	int n;
	cin>>n;

	if(n==1) {

		cout<<0<<endl;
		return 0;
	}

	long long int mod = 1e9+7;

	long long int a = 1, b = 1, c = 1;

	for(int i=1; i<=n; i++) {

		a = (a * 10) % mod;
	}

	for(int i=1; i<=n; i++) {

		b = (b * 9) % mod;
	}
	b = (b*2) % mod;

	for(int i=1; i<=n; i++) {

		c = (c * 8) % mod;
	}

	long long int ans;
	ans = (a-b+mod) % mod;
	ans = (ans+c+mod) % mod;
	
	cout<<ans<<endl;

	return 0;
}