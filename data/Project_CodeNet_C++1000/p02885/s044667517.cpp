#include <bits/stdc++.h> 
const long long MOD = 1e9+7;
using namespace std;


int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A,B;
	cin >> A >> B;

	if (A-(B*2)>=1) {
		cout << A-(B*2) << endl;
	} else {
		cout << 0 << endl;
	}
	return 0;
}
