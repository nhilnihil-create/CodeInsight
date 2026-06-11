#include "bits/stdc++.h"
using namespace std;

int main() {
	int N,K,Q;
	cin >> N>>K>>Q;
	vector<int> Count(N);
	for (int n = 0; n <Q; ++n) {
		int num;
		cin >> num;
		num--;
		Count[num]++;
	}
	for (int n = 0; n < N; ++n) {
		if ((K-Q + Count[n] )> 0) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No"<<endl;
		}
	}
	return 0;
}
