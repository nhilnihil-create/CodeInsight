#pragma GCC optimize ("O3")
#pragma GCC target ("sse4") // wonderful

#include <bits/stdc++.h>
using namespace std;


int main()
{

	int n; cin >> n;

	long double res = 0;

	for (int i=0; i < n; i++) {

		long double x; cin >> x;
		x = 1/x;
		res += x;

	}

	long double nres = 1/res;

	cout << nres;

	
	return 0;

}