#include <iostream>
#include <algorithm>

using namespace std;
typedef long long llong;

void solve_test()
{
	llong n, a, b;
	cin >> n >> a >> b;
	llong full = n / (a + b);
	cout << full * a + min(n % (a + b), a) << "\n";
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
