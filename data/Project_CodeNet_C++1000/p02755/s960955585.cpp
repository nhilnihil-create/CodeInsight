#include "bits/stdc++.h"

using namespace std;
int main() {
	int A, B;
	cin >> A >> B;
	for (int n = 0;n<=1000;++n) {
		if (A==n*8/100&&B==n*10/100) {
			cout <<n<<endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
