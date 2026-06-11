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
	int N, M;
	cin >> N >> M;
	
	vector<int> Ai(N, 0);
	int all_vote = 0;
	rep(i, N)
	{
		cin >> Ai.at(i);
		all_vote += Ai.at(i);
	}

	int ans = 0;
	rep(i, N)
	{
		if (Ai.at(i) >= 1.0 / (4.0*M)*all_vote)
		{
			ans++;
		}
	}

	if (M <= ans)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	return 0;
}