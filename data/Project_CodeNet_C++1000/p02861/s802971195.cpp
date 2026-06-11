#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <vector>
#include <map>
#include<cstdio>
#include<functional>
#include <bitset>
#include <iomanip>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define ll long long
using namespace std;
template <typename T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template <typename T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;

std::string substrBack(std::string str, size_t pos, size_t len) {
	const size_t strLen = str.length();

	return str.substr(strLen - pos, len);
}

int main()
{
	int n;
	cin >> n;
	vector<pair<double, double>> l(n);
	vector<double> d(n);
	rep(i, n) {
		double x, y;
		cin >> x >> y;
		l[i] = pair<double, double>(x, y);
		d[i] = i;
	}
	double ans = 0;
	double count = 0;
	do
	{
		for (int i = 1; i < d.size(); i++)
		{
			ans += sqrt(pow(abs(l[d[i - 1]].first - l[d[i]].first), 2) + pow(abs(l[d[i - 1]].second - l[d[i]].second), 2));
		}
		++count;
	} while (next_permutation(d.begin(), d.end()));
	ans /= count;
	std::cout << std::fixed;
	std::cout << std::setprecision(7);
	cout << ans << endl;
	system("pause");
}


