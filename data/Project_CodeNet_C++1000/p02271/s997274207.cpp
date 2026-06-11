#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> A(20);

bool solve(int i, int m)
{
	if (!m)
		return true;

	if (i >= n)
		return false;

	return solve(i + 1, m) || solve(i + 1, m - A[i]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> A[i];

	int q, m;
	cin >> q;
	while (q--)
	{
		cin >> m;
		if (solve(0, m))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}

	return 0;
}