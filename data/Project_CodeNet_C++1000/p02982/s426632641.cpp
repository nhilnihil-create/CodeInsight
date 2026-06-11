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
	int n, d;
	cin >> n >> d;
	vector<vector<double>> x(n, vector<double>(d));
	rep(i, n)
	{
		rep(j, d)
		{
			cin >> x[i][j];
		}
	}
	size_t ans = 0;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = i + 1; j < n; j++)
		{
			double distance = 0;
			for (size_t k = 0; k < d; k++)
			{
				distance += pow(x[i][k] - x[j][k], 2);
			}
			distance = sqrt(distance);
			if (distance == floor(distance))
			{
				ans++;
			}
		}
	}
	cout << ans << endl;

	return 0;
}