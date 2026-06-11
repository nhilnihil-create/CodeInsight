// C - Skolem XOR Tree
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	int n, k = 0;
	cin >> n;
	while ((1 << k) < n) k++;
	if ((1 << k) == n) {
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
		for (int i = 1; i < 3; i++) cout << i << ' ' << i + 1 << endl;
		cout << 3 << ' ' << n + 1 << endl;
		for (int i = 1; i < 3; i++) cout << (i + n) << ' ' << i + 1 + n << endl;
		for (int i = 4; i + 1 <= n; i += 2) {
			cout << (n + 1) << ' ' << i + 1 << endl;
			cout << i + 1 << ' ' << i << endl;
			cout << (n + 1) << ' ' << i + n << endl;
			cout << i + n << ' ' << i + 1 + n << endl;
		}
		if (n % 2 == 0) {
			bool found = false;
			for (int i = 2; i < n && !found; i++)
				for (int j = i + 1; j < n && !found; j++)
					if ((i ^ j ^ 1) == n) {
						found = true;
						cout << (i % 2 ? i : i + n) << ' ' << n << endl;
						cout << (j % 2 ? j : j + n) << ' ' << n * 2 << endl;
					}
		}
	}

	return 0;
}
