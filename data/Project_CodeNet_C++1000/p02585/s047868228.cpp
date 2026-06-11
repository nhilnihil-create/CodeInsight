#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;



const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
//const ll MOD = 1e9 + 7;
const ll MOD = 998244353;




int main() {
	int n, k;
	cin >> n >> k;

	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
	}

	vector<ll> c(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}

	ll ans = -INF;

	for (int i = 0; i < n; i++) {

		int pos = i;
		ll cycle_cnt = 0;
		ll cycle_sum = 0;
		
		do {
			
			cycle_cnt++;
			cycle_sum += c[pos];
			pos = p[pos];
			
		} while (pos != i);

		ll sum = 0;
		ll cnt = 0;

		do{
			
			cnt++;
			sum += c[pos];
			if (cnt > k) {
				break;
			}
			
			ll num = (k - cnt) / cycle_cnt;
			ll score = sum + max(0ll, cycle_sum) * num;
			ans = max(ans, score);
			pos = p[pos];
			
		} while (pos != i);

	}

	std::cout << ans << endl;
}
