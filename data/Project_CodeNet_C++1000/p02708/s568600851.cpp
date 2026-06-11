

#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const ll MOD = 1e9 + 7;


int main(int argc, char* argv[]) {
	
	int n, k;
	cin >> n >> k;


	ll cnt = 0;
	for (ll i = k; i <= n+1; i++) {
		ll mi = (i * (i - 1)) / 2;

		ll ma = (i * (2 * n - i + 1)) / 2;
		
		cnt = (cnt + ma - mi + MOD + 1) % MOD;
	}
	
	cout << cnt << endl;

}