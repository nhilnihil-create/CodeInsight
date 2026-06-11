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
	int n, d;
	cin >> n >> d;
	int sum = d * 2 + 1;
	if (n % sum)
		cout << (n / sum) + 1;
	else
		cout << (n / sum);
	return 0;
}
//04-08-2020 09:45:52
//------------------------------------------------------------------------------