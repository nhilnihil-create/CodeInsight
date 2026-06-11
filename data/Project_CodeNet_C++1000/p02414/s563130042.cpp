#include <iostream>

using namespace std;

int main()
{
	int n, m, l;
	cin >> n >> m >> l;
	long A[1001][1001], B[1001][1001], C[1001][1001];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> A[i][j];

	for (int i = 0; i < m; i++)
		for (int j = 0; j < l; j++)
			cin >> B[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < l; j++)
			for (int k = 0; k < m; k++)
				C[i][j] += A[i][k] * B[k][j];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < l; j++)
		{
			if (j > 0)
				cout << " ";
			cout << C[i][j];
		}
		cout << "\n";
	}
}


