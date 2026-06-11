#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string	s;
	cin >> s;

	int	count;
	count = 1;
	int	before_len;
	before_len = 1;
	for (int i = 1; i < s.size();)
	{
		if (before_len == 1 && s.at(i - 1) == s.at(i))
		{
			if (i == s.size() - 1)
				break;
			else
			{
				before_len = 2;
				i += 2;
			}
		}
		else
		{
			before_len = 1;
			i++;
		}
		count++;
	}
	cout << count << endl;
}
