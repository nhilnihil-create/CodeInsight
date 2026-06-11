#include "bits/stdc++.h"
using namespace std;
int main() {
	int N,K,C;
	cin >> N >> K >> C;
	string S;
	cin >> S;
	string R = S;
	C++;
	reverse(R.begin(), R.end());
	vector<int>Str(K);
	{
		int tmp = -C;
		for (int n = 0; n < K; ++n) {
			tmp += C;
			while (true) {
				if ('o' == S[tmp]) {
					Str[n] = tmp; 
					//cout << tmp << endl;
					break;
				}
				else {
					tmp++;
				}
			}
		}
	}
	vector<int>End(K);
	{
		int tmp = -C;
		for (int n = 0; n < K; ++n) {
			tmp += C;
			while (true) {
				if ('o' == R[tmp]) {
					End[n] = tmp;
					//cout << tmp << endl;
					break;
				}
				else {
					tmp++;
				}
			}
		}
	}
	for (int n = 0; n < K; ++n) {
		if (Str[n]  == (N-1) - End[K - n-1]) {
			cout << Str[n] + 1<<endl;
		}
	}
	return 0;
}
