#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;

int main(){
	ll n,m;cin>>n>>m;
	ll lcm=(n*m)/__gcd(n,m);
	cout<<lcm;
	return 0;
}
