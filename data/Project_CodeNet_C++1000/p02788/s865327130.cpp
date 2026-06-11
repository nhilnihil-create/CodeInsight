#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<set>
#include<deque>
#include<iomanip>
#include<tuple>
#include<stack>

#define _USE_MATH_DEFINES
#include<math.h>


using namespace std;
typedef long long ll;

typedef pair<ll, ll> pll;
typedef tuple<int, int, int> ti3;

const ll MOD_CONST = 1000000007;
//const ll MOD_CONST = 998244353;


const int INF = 1000000000;
//const ll INF = 1000000000000000000;

int main() {
	int n, d, a;
	cin >> n >> d >> a;

	vector<pll> monst(n);
	for (int i = 0; i < n; i++) {
		cin >> monst[i].first >> monst[i].second;
	}

	sort(monst.begin(), monst.end());

	priority_queue<pll,vector<pll>,greater<pll>> pq;

	ll sum = 0;

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		while (!pq.empty()) {
			int p = pq.top().first;

			if (p >= monst[i].first) {
				break;
			}

			sum -= pq.top().second;
			pq.pop();

		}
	
		ll hp = monst[i].second;
		hp -= sum;

		if (hp <=0) {
			continue;
		}

		ll num = hp / a;
		if (hp % a != 0) {
			num++;
		}

		ll atk = num * a;
		sum += atk;
		ans += num;

		ll maxD = monst[i].first + 2 * d;
		pq.push(make_pair(maxD, atk));
		

	}

	cout << ans << endl;
	
}

