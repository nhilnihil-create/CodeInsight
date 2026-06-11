#include <iostream>
using namespace std;

int main()
{
	int n, m, p;
	while (cin >> n >> m >> p, n + m + p)
	{
		int winner = 0;
		int total = 0;
		for (int i = 1; i <= n; i++)
		{
			int tmp;
			cin >> tmp;
			total += tmp * 100;
			if (i == m) winner = tmp;
		}
		if (winner == 0)
			cout << 0 << endl;
		else
			cout << total * (100 - p) / 100 / winner << endl;
	}

	return 0;
}