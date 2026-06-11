#include <bits/stdc++.h> 
const long long MOD = 1e9+7;
using namespace std;


int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);

	unsigned int A,B;
	cin >> A >> B;

	if (A<=9 && B<=9 && A*B) {
		cout << A*B << endl;
	} else {
		cout << "-1" << endl;
	}
	return 0;
}
