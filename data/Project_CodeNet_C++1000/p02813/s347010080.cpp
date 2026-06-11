#include <bits/stdc++.h>
using namespace std;

void solve(int N, std::vector<int> P, std::vector<int> Q)
{
	int a = 0, b = 0, i = 0;
	vector<int> v(N);
	iota(v.begin(), v.end(), 1);

	do
	{
		if (P == v)
			a = i;

		if (Q == v)
			b = i;

		i++;
	} while (next_permutation(v.begin(), v.end()));

	cout << abs(a - b) << endl;
}

int main()
{
	int N;
	scanf("%d", &N);
	std::vector<int> P(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &P[i]);
	}
	std::vector<int> Q(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &Q[i]);
	}
	solve(N, std::move(P), std::move(Q));
	return 0;
}
