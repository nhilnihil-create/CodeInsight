#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main(void) {
	int a, b, c, d, k;
	cin >> a >> b >> c >> d >> k;

	int m = a * 60 + b;
	int n = c * 60 + d;

	cout << n - m - k << endl;
	
	return 0;
}