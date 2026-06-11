#include <bits/stdc++.h>
using namespace std;
int main(){
	int k;
	cin >> k;
	if(k%2 == 0 || k%5 == 0){
		cout << -1 << '\n';
		return 0;
	}

	long long n = 7, i;
	for (i = 1; i <= k; ++i) {
		if(n%k == 0)
			break;
		n = (n * 10 + 7) % k;
	}

	cout << i << '\n';
	return 0;
}
