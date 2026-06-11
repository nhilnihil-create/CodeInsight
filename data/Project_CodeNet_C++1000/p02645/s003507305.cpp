#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#define int long long
#define all(x) (x).begin(), x.end()
#define allr(x) (x).rbegin(), x.rend()

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9;

void fast()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

signed main()
{
	fast();
	string s;
	cin >> s;
	cout << s[0] << s[1] << s[2] << '\n';
	return 0;
}
