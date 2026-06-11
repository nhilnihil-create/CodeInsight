#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <iomanip>
#include <unordered_map>

using namespace std;
typedef long long  ll;

int main()
{
	ll K;
	string str;
	cin >> str >> K;
	ll cnt = 0;
	char focus = str[0];
	ll ans = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == focus)
		{
			cnt++;
		}
		else
		{
			ans += cnt / 2;
			focus = str[i];
			cnt = 1;
		}
	}
	if (cnt == str.size())
	{
		cout << K * cnt / 2 << endl;
		return 0;
	}
	ans += cnt / 2;
	ans *= K;
	ll a = 0, b = 0;
	focus = str[0];
	while (focus == str[a])
	{
		a++;
		if (str[a] != focus)
		{
			break;
		}
	}
	focus = str[str.size() - 1];
	while (focus == str[str.size() - 1 - b])
	{
		b++;
		if (str[str.size() - 1 - b] != focus) break;
	}
	if (str[0] == str[str.size() - 1])
		ans = ans - (K - 1) * (a / 2 + b / 2 - (a + b) / 2);
	cout << ans << endl;
	return 0;
}