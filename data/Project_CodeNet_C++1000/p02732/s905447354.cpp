#include <algorithm>
#include <cmath>
#include <iostream>
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
	vector<ll> vote((N + 1), 0);

	int t;
	rep(i, N)
	{
		cin >> t;
		Ai.at(i) = t;
		vote[t] += 1;
	}
	
	ll all = 0;
	for (int i = 1; i <= N; ++i)
	{
		all += vote[i] * (vote[i] - 1) / 2;
	}
	
	ll ans;
	int before, after, val;
	for (int i = 0; i < N; ++i)
	{
		val = vote[Ai[i]];
		before = val * (val - 1) / 2;
		after = (val -1) * (val - 2) / 2;

		ans = all - before + after;
		cout << ans << endl;
	}

	return 0;
}