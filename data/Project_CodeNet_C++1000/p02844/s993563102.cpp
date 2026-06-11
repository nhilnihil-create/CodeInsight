#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
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
	string S;

	cin >> N >> S;
	set<string> s_set;
	int ans = 0;

	for (int i = 0; i < 1000; ++i)
	{
		string ls = to_string(i);
		if (ls.size() == 1) ls = "00" + ls;
		if (ls.size() == 2) ls = "0" + ls;

		int cnt = 0;
		bool find = false;
		for (int j = 0; j < N; ++j)
		{
			if (S[j] == ls[cnt]) cnt++;
			if (cnt == 3)
			{
				find = true;
				break;
			}
		}

		if (find) ans += 1;
	}

	cout << ans << endl;
	return 0;
}