#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<set>
#include<deque>
using namespace std;
typedef long long ll;

typedef pair<int, int> pii;

const ll MOD_CONST = 1000000007;


const int BIG_INT = 1000000000;
const ll BIG_NUM = 1000000000000000000;



int main() {
	int n, k;
	cin >> n >> k;

	vector<vector<int>> g(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}

	vector<ll> facto(k + 1);
	vector<ll> inv_mod(k + 1);
	vector<ll> inv_facto(k + 1);
	facto[0] = inv_mod[1] = inv_facto[0] = 1;
	for (int i = 2; i <= k; i++) {
		inv_mod[i] = (MOD_CONST - (inv_mod[MOD_CONST % i] * (MOD_CONST / i)) % MOD_CONST) % MOD_CONST;
	}

	for (int i = 1; i <= k; i++) {
		facto[i] = (i * facto[i - 1]) % MOD_CONST;
		inv_facto[i] = (inv_mod[i] * inv_facto[i - 1]) % MOD_CONST;
	}

	ll ans = k;
	vector<bool> isChecked(n);
	queue<int> que;
	que.push(0);
	while (!que.empty()) {
		int v = que.front();
		que.pop();
		int e = g[v].size();
		if (v != 0) {
			e--;
		}

		if (e > k - 1) {
			ans *= 0;
			continue;
		}
		ans = (ans * facto[k - 1]) % MOD_CONST;
		ans = (ans * inv_facto[k - 1 - e]) % MOD_CONST;


		if (v == 0) {
			k--;
		}

		for (auto it = g[v].begin(); it != g[v].end(); it++) {
			if (!isChecked[*it]) {
				que.push(*it);
			}
		}

		isChecked[v] = true;
		
	}

	cout << ans << endl;

}


