#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using str = string;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
const double PI = 3.141592653589793238;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define REP(i, m, n) for (int i = m; i < (int)n; i++)
#define all(a) (a).begin(), (a).end()
#define allg(a) (a).begin(), (a).end(), greator<>()
#define d20 std::setprecision(20)
#define veci vector<int>
#define vecll vector<long long int>
#define vecb vector<bool>
#define vecd vector<double>
template <typename T>
T lcm(T a, T b)
{
	return a / __gcd(a, b) * b;
}

int main()
{
	int n, m, ans = -1;
	cin >> n >> m;
	vector<pair<int, char>> sc(m);
	rep(i, m)
	{
		int s;
		char c;
		cin >> s >> c;
		s--;
		sc[i] = make_pair(s, c);
	}
	for (int i = 999; i >= 0; i--)
	{
		str tmp = to_string(i);
		if ((int)tmp.size() != n)
			continue;
		bool is_ok = true;
		rep(j, m) if (tmp[sc[j].first] != sc[j].second) is_ok = false;
		if (is_ok)
			ans = i;
	}
	cout << ans << endl;
	return 0;
}