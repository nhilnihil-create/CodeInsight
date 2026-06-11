#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int A, B, K;

	cin >> A >> B >> K;

	if (A >= K)
		A = A - K;
	else
	{
		K = K - A;
		A = 0;
		if (B >= K)
			B = B - K;
		else
			B = 0;
	}
	cout << A << ' ' << B << endl;
}
