#include <iostream>
using namespace std;

int a[2009], b[2009];
long long d[2009][2009], md = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
		cin >> b[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (a[i] == b[j]) d[i][j] = (d[i - 1][j] + d[i][j - 1] + 1) % md;
			else d[i][j] = (d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + 2 * md) % md;
		}
	cout << (d[n][m] + 1) % md << '\n';
	return 0;
}	