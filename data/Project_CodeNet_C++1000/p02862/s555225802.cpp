#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll mod = 1000000007;

int inv(int n){
	if(n == 1)return 1;
	return (mod - mod/n)*1LL*inv(mod%n)%mod;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int x, y;
	cin>>x>>y;
	if((x + y)%3){
		cout<<0<<endl;
		exit(0);
	}
	int a = x - (x + y)/3;
	int b = y - (x + y)/3;
	if(a < 0 || b < 0){
		cout<<0<<endl;
		exit(0);
	}
	ll num = 1, den = 1;
	for(int i = 1; i <= a; i++){
		(num *= (b + i)) %= mod;
		(den *= i) %= mod;
	}
	ll ans = num*inv(den)%mod;
	cout<<ans<<endl;

	return 0;
}