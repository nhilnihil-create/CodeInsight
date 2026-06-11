#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

namespace {

	int cnt;
	void InsertionSort(vector<int>& A, int g)
	{
		for (int i = g; i < A.size(); ++i)
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

	void ShellSort(vector<int>& A)
	{
		cnt = 0;
		vector<int> G;
		for (int i = 1; i <= A.size(); i = 3 * i + 1)
			G.push_back(i);
		reverse(G.begin(), G.end());

		for (auto i : G)
			InsertionSort(A, i);

		cout << G.size() << endl;
		cout << G[0];
		for (auto it = G.begin() + 1; it != G.end(); ++it)
			cout << ' ' << *it;
		cout << endl;
		cout << cnt << endl;
		for (auto i : A)
			cout << i << endl;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> A(n);
	for (int i = 0; i < n; ++i)
		cin >> A[i];

	ShellSort(A);

	return 0;
}