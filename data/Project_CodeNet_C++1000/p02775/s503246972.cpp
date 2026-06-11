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
	string N;
	cin >> N;
	int ans = 0;
	bool plus = false;
	for (int i = N.size()-1; i >= 0; i--)
	{
		int a = N[i] - '0';
		if (plus)
			a++;
		if (a == 10)
			plus = true;
		if (a == 5)
		{
			if (i > 0 && N[i-1] > '4')
				plus = true;
			else
				plus = false;
			ans += 5;
		}
		else if (a < 6)
		{
			ans += a;
			plus = false;
		}
		else
		{
			ans += 10 - a;
			plus = true;
		}
	}
	if (plus)
		ans++;
	cout << ans << endl;
}

