#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, K;
	cin >> N >> K; 
	string S;
	cin >> S;
	int num = 0;
	for (int n = 0;n<S.size();++n) {
		if (0 == n) {
			++num;
		}
		else {
			if (S[n-1] !=S[n]) {
				num++;
			}
		}
	}
	int tmp = max(1, num-2*K);
	cout << N-tmp<<endl;
	return 0;
}
