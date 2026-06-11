#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007; // 998244353
using ll = long long;
using namespace std;

ll power( ll a, ll b ){
	ll res = 1;
	while( b > 0 ){
		if( b & 1 ) res = res*a % mod;
		a = a*a % mod;
		b >>= 1;
	}
	return res;
}

int main(){
	ll n; cin >> n;
	cout << ( ( power(10, n) - ( power(9, n) * 2 ) + mod + mod ) % mod + power(8, n) ) % mod << endl;
}