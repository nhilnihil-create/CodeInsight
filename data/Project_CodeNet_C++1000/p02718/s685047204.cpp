#include "bits/stdc++.h"

using namespace std;

int main() {
	int N, M;
	cin >> N >> M; 
	int sum = 0;
	vector<int>A(N);
	for (int n = 0;n<N;++n) {
		cin >> A[n];
		sum += A[n];
	}
	int count = 0;
	for (int n = 0;n<N;++n) {
		if (A[n]*4*M >=sum) {
			count++;
		}
	}
	if (count >=M) {
		cout << "Yes" << endl;
	}
	else {
		cout <<"No"<<endl;
	}
	return 0;
}