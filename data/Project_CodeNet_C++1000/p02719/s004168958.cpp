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


int main()
{
	ll N, K;
	cin >> N >> K;

	ll last_N = (ll)(2e18);
	N = N % K;

	while (true)
	{
		last_N = N;
		N = abs(N - K);
		if (N >= last_N || N < 0)
		{
			N = last_N;
			break;
		}
	}

	cout << N << endl;
	return 0;
}