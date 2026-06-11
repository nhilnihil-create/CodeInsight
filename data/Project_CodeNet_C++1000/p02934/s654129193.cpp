#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>A(N); 
	double tmp = 0;
	for (int n = 0;n<N;++n) {
		cin >> A[n];
		tmp += 1.0 / A[n];
	}
	printf("%.10f\n", 1/tmp);
	
	return 0;
}