#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[])
{
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());
	ll ans = 0;

	for (int i = 0; i < k; ++i)
		ans += v[i];
	
	cout << ans;

	return 0;
}