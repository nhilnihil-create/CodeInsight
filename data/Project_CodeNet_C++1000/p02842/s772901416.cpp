#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long N;

	cin >> N;

	long long X;
	long long ans = -1;


	X = N / 1.08;

	if ((long long)((X + 1) * 1.08) == N)
		ans = X + 1;
	else if ((long long)((X - 1) * 1.08) == N)
		ans = X - 1;
	else if ((long long)(X) * 1.08 == N)
		ans = X;


	if (ans != -1)
		cout << ans << endl;
	else
		cout << ":(" << endl;
}
