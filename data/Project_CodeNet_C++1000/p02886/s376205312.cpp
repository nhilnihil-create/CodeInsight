#pragma GCC optimize ("O3")
#pragma GCC target ("sse4") // wonderful

#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n; cin >> n;
	int d[n+10];
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}

	int res = 0;

	for (int i = 0; i < n; i++) 
		for (int j = i+1; j < n; j++) {
			res += d[i] * d[j];
		}


	cout << res;

	return 0;

}