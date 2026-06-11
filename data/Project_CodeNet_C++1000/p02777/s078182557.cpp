#include <bits/stdc++.h>

using namespace std;

int main()
{
	string S, T;
	int A, B;
	string U;
	cin >> S >> T >> A >> B >> U;
	if (U == S)
		cout << max(A - 1,0) << " " << B << "\n";
	else if ( U == T)
		cout << A << " " << max(B-1, 0) << "\n";
	else
		cout << A << " " << B << "\n";

	return 0;
}
