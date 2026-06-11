//https://atcoder.jp/contests/abc134
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e6 + 5;
const double E = 1e-9;

//------------------------------------------------------------------------------

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*ifstream cin("input.txt");
	ofstream cout("output.txt");*/
	int n;
	cin >> n;
	vector<int> a(n), b;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	b = a;
	sort(b.begin(), b.end(), greater<int>());
	for (int i = 0; i < n; i++)
	{
		if (a[i] == b[0])
			cout << b[1] << "\n";
		else
			cout << b[0] << "\n";
	}
	return 0;
}
//04-08-2020 09:49:23
//------------------------------------------------------------------------------