#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e2 + 5;
const int INF = 1e9 + 7;

int a;
double b;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b;
	int c = round(b * 100);
	int ans = a * c;
	ans /= 100;
	cout << ans;
	return 0;
}
//10-09-2020 18:48:49