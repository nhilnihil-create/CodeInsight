
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const ll MOD = 1e9 + 7;


int main(int argc, char* argv[]) {
	int n, k;
	cin >> n >> k;

	map<ll, ll> m;
	for (int i = k; i >= 1; i--) {
		ll cnt = 1;
		int num = k / i;
		
		ll pi = num;


		ll tmp = n;
		for (int j = 0; j < 32; j++) {
			if (((n >> j)&1)==1) {
				
				cnt = (cnt * pi) % MOD;
			}
			pi = (pi * pi) % MOD;
		}
		
		
		

		for (int j = 2 * i; j <= k; j += i) {
			cnt =(cnt + MOD - m[j])%MOD;
		}

		m[i] = cnt;
	}


	ll sum = 0;
	for (auto it = m.begin(); it != m.end(); it++) {
		sum = (sum + (it->first * it->second) % MOD) % MOD;
	}

	cout << sum << endl;


}