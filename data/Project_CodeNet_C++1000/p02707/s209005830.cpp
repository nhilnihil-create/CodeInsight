#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int a[200000] = {};
	int t;
	for (int i = 1; i < n; i++) {
		cin >> t;
		a[t - 1]++;
	}

	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}

	return 0;
}
