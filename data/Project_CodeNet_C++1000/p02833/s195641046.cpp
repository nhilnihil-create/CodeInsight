// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	long long n;
	cin >> n;
	if(n & 1) {
		cout << 0;
		exit(0);
	}

	n /= 2;

	long long c = 0;
	while(n) {
		c += n / 5;
		n /= 5;
	}

	cout << c;
	

	return 0;
}
