#include"bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
	int h, a;
	cin >> h >> a;
	int k = 0;

	while (h>0) {
		h -= a;
		k++;
	}

	cout << k << endl;
	return 0;
}