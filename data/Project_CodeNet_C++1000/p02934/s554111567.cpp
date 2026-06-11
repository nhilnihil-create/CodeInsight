#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll MOD = 1000000007;

int main(int, char**) {
	int n;
	cin >> n;
	double ainv;
	for (int i=0; i<n; i++) {
		int a; cin >> a;
		ainv += pow(a, -1);
	}
	cout << setprecision(10) << pow(ainv, -1) << endl;
	return 0;
}