#include <bits/stdc++.h>
using namespace std;
using ll = int_fast64_t;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;
#define fast() ios::sync_with_stdio(false), cin.tie(nullptr)
#define digit(N) cout << fixed << setprecision((N))
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int main()
{
	ll K;
	int N;
	cin >> N >> K;
	vector<int> a(N);
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
		a[i]--;
	}

	int sz = 60;
	vector<vector<int>> next(sz + 1, vector<int>(N, -1));

	for (int i = 0; i < N; i++)
	{
		next[0][i] = a[i];
	}

	for (int k = 0; k < sz; k++)
	{
		for (int i = 0; i < N; i++)
		{
			if (next[k][i] == -1)
				continue;

			next[k + 1][i] = next[k][next[k][i]];
		}
	}

	int ans = 0;

	for (int k = sz - 1; k >= 0; k--)
	{
		if (ans == -1)
			break;

		if ((K >> k) & 1)
			ans = next[k][ans];
	}

	cout << ans + 1 << "\n";
}