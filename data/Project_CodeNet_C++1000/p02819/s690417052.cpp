#include "bits/stdc++.h"

using namespace std;
vector<int>P;
bool f(int n) {
	for (int m = 0; m < P.size(); ++m) {
		if (0 == n % P[m]) {
			return false;
		}
	}
	return true;
}



int main() {
	int X;
	cin >> X;
	for (int n = 2;n<200000;++n) {
		if (!f(n)) {
			continue;
		}
		if (n < X) {
			P.push_back(n);
		}else{
			cout <<n <<endl;
			return 0;
		}
	}
	
	return 0;
}
