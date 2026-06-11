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
	int n;
	cin >> n;
	vector<P> x(n);
	rep(i, n)
	{
		cin >> x[i].second >> x[i].first;
	}
	sort(all(x));
	int now_time = 0;
	bool is_ok = true;
	rep(i, n)
	{
		now_time += x[i].second;
		if (now_time > x[i].first)
			is_ok = false;
	}
	cout << (is_ok ? "Yes" : "No") << endl;
	return 0;
}