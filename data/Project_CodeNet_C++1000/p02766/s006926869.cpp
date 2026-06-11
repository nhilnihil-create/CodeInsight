#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n, k;
	cin >> n >> k;
	int i = 1;
	while (true) {
		if (n < pow(k, i)) {
			cout << i << endl;
			return 0;
		}
		else i++;
	}
}