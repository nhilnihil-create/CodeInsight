#include "bits/stdc++.h"

using namespace std;



int main() {
	int N,M ;
	cin >> N >> M;
	vector<int>A(M);
	int day = 0;
	for (int i = 0;i<M;++i) {
		cin >> A[i];
		day += A[i];
	}
	if (day <= N) {
		cout << N - day <<endl;
	}
	else{
		cout << "-1" << endl;
	}
	return 0;
}