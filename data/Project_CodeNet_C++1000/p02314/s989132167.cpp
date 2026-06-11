#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int d[21];
	int DP[50001];
	for (int i = 0;i < m;i++) {
		cin >> d[i];
	}
	for (int i = 0;i < n+1;i++) {
		DP[i] = 100000;
	}
	DP[0] = 0;
	for (int i = 0;i < m;i++) {
		for (int j = 0; j < n-d[i]+1; j++) {
			if (DP[j + d[i]] > DP[j] + 1)
				DP[j + d[i]] = DP[j] + 1;
		}
	}

	cout << DP[n] << endl;

	return 0;
}