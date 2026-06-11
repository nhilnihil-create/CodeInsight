#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool LinearSearch(vector<int> A, int n, int num)
{
	int i = 0;

	A.push_back(num);
	while (A[i] != num)
		i++;

	return (i != n);
}

int main()
{
	int N, Q, t;
	int sum = 0;
	cin >> N;

	vector<int> S(N);
	for (int i = 0;i < N;i++)
		cin >> S[i];

	cin >> Q;

	for (int i = 0;i < Q;i++)
	{
		cin >> t;

		if (LinearSearch(S, N, t))
			sum++;
	}

	cout << sum << endl;

	return 0;
}