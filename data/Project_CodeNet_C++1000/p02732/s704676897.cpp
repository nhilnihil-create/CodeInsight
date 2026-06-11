#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <stdio.h>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double PI = 3.1415926535897932;

/* a と b の最大公約数を返す関数 */
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

int main()
{
	int N;
	cin >> N;

	vector<int> Ai(N, 0);
	map<ll, ll> v_map;

	int t;
	rep(i, N)
	{
		cin >> t;
		Ai.at(i) = t;
		v_map[t]++;
	}
	
	ll all = 0;
	for (auto it : v_map)
	{
		all += (it.second) * (it.second - 1) / 2;
	}

	ll ans;
	int before, after, val;
	for (int i = 0; i < N; ++i)
	{
		val = v_map[Ai[i]];
		before = val * (val - 1) / 2;
		after = (val -1) * (val - 2) / 2;

		ans = all - before + after;
		cout << ans << endl;
	}

	return 0;
}