#pragma GCC optimize ("O3")
#pragma GCC target ("sse4") // wonderful

#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n; cin >> n;
	int res = 0;

	for (int i = 1; i <= n; i++) {
		if (i % 2 != 0) {
			res++;
		}
	}

	float answer = res;
	float N = n;

	cout << (answer / N);


	return 0;

}