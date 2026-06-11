#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007;	// 998244353
using ll = long long;
using namespace std;

int main(){
	ll n; cin >> n;
	if( n == 1 ){
		cout << 0 << endl;
		return 0;
	}
	map<ll, int> pf;
	ll t = n;
	ll letzte = -1;
	for( ll k = 2; k*k <= n; ++k ){
		while( t%k == 0 ){
			t /= k;
			++pf[k];
			letzte = k;
		}
	}
	if( letzte == -1 ){
		cout << 1 << endl;
		return 0;
	}
	if( t != 1 ){
		++pf[t];
		letzte = t;
	}
	int cnt = 0;
	for( auto a : pf ){
		int k = a.second;
		int sum = 0, i = 1;
		while( true ){
			sum += i;
			if( sum > k ){
				--i;
				break;
			}
			++i;
		}
		cnt += i;
	}
	cout << cnt << endl;
}