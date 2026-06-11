#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<int, int>
#define dd pair<double, double>
#define pb(i) push_back(i)
const double PI = 3.14159265359;
const int inf = 1e9+77;
const ll mod = 1e9+7;
const double eps = 1e-7;
//int dir1[8] = {0, 0, 1, -1, 1, -1, 1, -1};
//int dir2[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dir1[4] = {0, 0, 1, -1};
int dir2[4] = {1, -1, 0, 0};

const int N = 1e6;

int main()
{
	int i, j;

	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<int> w(n + 5, 0), r(n+5, 0);
	for(i = 0; i < n; i++)
	{
		w[i+1] = w[i] + ((s[i] == 'W') ? 1 : 0); 
		r[i+1] = r[i] + ((s[i] == 'R') ? 1 : 0);
	}

	int ans = inf;
	for(i = 0; i <= n; i++)
	{
		int b = (r[n]-r[i]);
		int a = w[i];
		
		ans = min(ans, a + b - min(a, b));
	}

	cout << ans << '\n';
}
