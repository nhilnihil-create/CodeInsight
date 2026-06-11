#include <bits/stdc++.h>

using namespace std;

int main()
{

	long long A, B, C, K, sum;

	cin >> A >> B >> C >> K;

	if (K <= A)
		sum = K;
	else if (A < K && K < A + B)
		sum = A;
	else if (A + B <= K && K <= A + B + C)
		sum = A - (K - A - B);

	cout << sum << endl;
}
