#include "bits/stdc++.h"
using namespace std;

int D(int x,int y) {
	return max(x - y, y - x);
}


int main() {
	int N,X,Y;
	cin >> N >> X >> Y;
	X--;
	Y--;
	vector<int>Ans(N);
	for (int i = 0;i<N;++i) {
		for (int j = i + 1; j < N; ++j) {
			int num = min(min(j - i, D(X, i) + 1 + D(Y, j)), D(X, j) + 1 + D(Y, i));
			Ans[num]++; 
		}
	}
		for (int i = 1;i < N;++i) {
		cout <<Ans[i] << endl;
	}
	return 0;
}