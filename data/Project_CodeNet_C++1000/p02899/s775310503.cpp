#define alphanso                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(NULL)
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
int main()
{
	alphanso;
	int n, x, i;
	cin >> n;
	map<int, int> m;
	for (i = 1; i <= n; i++)
	{
		cin >> x;
		m[x] = i;
	}
	for (auto it = m.begin(); it != m.end(); it++)
		cout << it->second << " ";
	return 0;
}