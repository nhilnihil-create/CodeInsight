#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

namespace {
	int cnt, m;
	vector<int> G;

	void InsertionSort(vector<int>& A, int n, int g)
	{
		for (int i = g; i < n; ++i)
		{
			int v = A[i];
			int j = i - g;

			while (j >= 0 && A[j] > v) {
				A[j + g] = A[j];
				j -= g;
				cnt++;
			}

			A[j + g] = v;
		}
	}

	void ShellSort(vector<int>& A, int n)
	{
		cnt = 0;
		for (int i = 0; i <= n; ++i)
		{
			int g = pow(2, i + 1) - 1; // 2^(k+1)-1, ..., 7, 3, 1(k >= 0)
			if (g <= n) G.push_back(g);
			else { m = i; reverse(G.begin(), G.end()); break; }
		}

		for (int i = 0; i < m; ++i)
			InsertionSort(A, n, G[i]);
	}
}

int main()
{
	int n;
	cin >> n;

	vector<int> A(n, 0);
	for (int i = 0; i < n; ++i)
		cin >> A[i];

	ShellSort(A, n);

	cout << m << endl;
	for (int i = 0; i < m; ++i) {
		cout << G[i];
		i != m - 1 ? cout << " " : cout << endl;
	}
	cout << cnt << endl;
	for (int i = 0; i < n; ++i)
		cout << A[i] << endl;

	return 0;
}