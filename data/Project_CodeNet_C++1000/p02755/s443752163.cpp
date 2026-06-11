#include <iostream>

using namespace std;
typedef long long llong;

void solve_test()
{
	int a, b;
	cin >> a >> b;

	for (int ans = 1; ans <= 2000; ans++)
	{
		int first = int(0.08 * ans);
		int second = int(0.1 * ans);
		if (first == a && second == b)
		{
			cout << ans << "\n";
			return;
		}
	}
	cout << "-1\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tests = 1;
	//cin >> tests;
	while (tests--)
		solve_test();

	return 0;
}
