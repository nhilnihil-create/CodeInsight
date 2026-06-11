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
	int N, X, Y;
	cin >> N >> X >> Y;
	--X, --Y;
	vector<vector<int>> vi(N, vector<int>(N, -1));

	for (int st = 0; st < N; ++st)
	{
		int len = 0;
		queue<int> que;
		que.push(st);
		vi[st][st] = 0;

		while (!que.empty())
		{
			vector<int> nd;
			int c = que.front(); que.pop();

			// 次の行き先
			if (c > 0) nd.push_back(c - 1);
			if (c < (N-1)) nd.push_back(c + 1);
			if (c == X) nd.push_back(Y);
			if (c == Y) nd.push_back(X);

			// 行先に応じて探索
			for (auto nc : nd)
			{
				if (vi[st][nc] == -1)
				{
					vi[st][nc] = vi[st][c] + 1;
					que.push(nc);
				}
			}
		}
	}

	// 結果を数える
	vector<int> rec(N, 0);
	for (int i = 0; i < N; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
				rec[vi[i][j]] += 1;
		}
	}

	for (int i = 1; i < N; ++i)
	{
		cout << rec[i] << endl;
	}

	return 0;
}