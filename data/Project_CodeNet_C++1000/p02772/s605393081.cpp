#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n; cin >> n;
	int A[1001], ok = 1;
	for (int i = 0; i < n; ++i)
	{
		cin >> A[i];
		if (A[i] % 2 == 0)
			if (A[i] % 3 != 0 & A[i] % 5 != 0)
				ok = 0;
	}
	cout << (ok ? "APPROVED" : "DENIED") << endl;
}

