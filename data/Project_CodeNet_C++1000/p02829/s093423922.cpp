#include <bits/stdc++.h> 
const long long MOD = 1e9+7;
using namespace std;


int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A,B;
	cin >> A >> B;

	if (A==1 && B==2) {
		cout << 3 << endl;
	} else if (A==2 && B==3) {
		cout << 1 << endl;
	} else if (A==3 && B==1) {
		cout << 2 << endl;
	} else if (A==2 && B==1) {
		cout << 3 << endl;
	} else if (A==3 && B==2) {
		cout << 1 << endl;
	} else if (A==1 && B==3) {
		cout << 2 << endl;
	}
	return 0;
}
