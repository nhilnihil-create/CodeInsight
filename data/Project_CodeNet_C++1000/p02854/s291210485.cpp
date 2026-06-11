#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<ll, ll>>;
// ceil() 切り上げ, floor() 切り捨て
// next_permutation(all(x))

int		main(void)
{
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	ll L = 0, R = 0;
	int i = 0, j = N-1;
	while (i != j)
	{
		if (L < R)
			L += A[i++];
		else
			R += A[j--];
	}
	if (L < R)
		L += A[i++];
	else
		R += A[j--];
	cout << abs(L-R) << endl;
}

