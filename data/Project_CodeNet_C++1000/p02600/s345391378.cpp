#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	int k = 8;
	for (int i=600; i<=2000; i+=200) {
		if (n<i) {
			break;
		}
		k--;
	}
	cout << k << '\n';
	
	return 0;
}
