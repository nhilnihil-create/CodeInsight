#include <algorithm>
#include <cmath>
#include <iostream>
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

void rec(int d, long long val, vector<long long> &all)
{
	// 格納
	all.push_back(val);

	// 10桁打ち切り
	if (d == 10) return;

	int md = val % 10;
	// 次へ進む処理
	for (int i = -1; i <= 1; ++i)
	{
		md = val % 10 + i;
		if (md >= 0 && md <= 9) rec(d + 1, val * 10 + md, all);
	}

	return;
}

int main()
{
	int K;
	cin >> K;

	int d = 0;
	vector<ll> all;
	for (int i = 1; i <= 9; ++i)
	{
		rec(1, i, all);
	}

	sort(all.begin(), all.end());
	cout << all.at(K - 1) << endl;

	return 0;
}