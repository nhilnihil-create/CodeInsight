#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main()
{
	int k, n;
	cin >> k >> n;
	vector<int> a(n);
	rep(i, n)
	{
		cin >> a[i];
	}
	int max_d = k - a[n - 1] + a[0];
	rep2(i, 1, n)
	{
		max_d = max(max_d, a[i] - a[i - 1]);
	}
	cout << k - max_d << endl;
	return 0;
}
