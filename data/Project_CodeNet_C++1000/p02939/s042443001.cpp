#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<ll, ll>>;
// ceil() 切り上げ, floor() 切り捨て
// next_permutation(all(x))

int		main(void)
{
	string S;
	cin >> S;
	string A;
	A += S[0];
	int ans = 1, i = 1, j = 1;
	while (i + 1 <= S.size())
	{
		j = 1;
		while (A == S.substr(i, j))
		{
			j++;
			if (i + j > S.size())
			{
				cout << ans << endl;
				return (0);
			}
		}
		ans++;
		A = S.substr(i, j);
		i += j;
	}
	cout << ans << endl;
	return (0);
}

