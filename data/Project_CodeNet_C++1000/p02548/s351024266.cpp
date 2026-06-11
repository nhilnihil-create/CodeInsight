#include <iostream>
#include <cmath>

using namespace std;

void solve() 
{
	int n; cin >> n;

	int ans = 0;
	int e = sqrt(n);
	for(int i = 1; i <= e; ++i) 
	{
		int j = i;
		while(i * j < n)
			++j;

		ans += 2 * (j - i);
		if(i != j)
			--ans;
	}
	cout << ans << '\n';
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "rt", stdin);
   freopen("output.txt", "wt", stdout);
#endif

   	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
	return 0;
}

