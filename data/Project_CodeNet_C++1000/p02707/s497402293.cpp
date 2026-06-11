#include "bits/stdc++.h"
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int>V(N+1);
	for (int n = 0;n< N - 1;++n) {
		int m = 0;
		cin >> m;
		V[m]++;
	}
	
	for (int i = 1;i <= N;++i) {
		cout << V[i] << endl;
	}
	return 0;
}