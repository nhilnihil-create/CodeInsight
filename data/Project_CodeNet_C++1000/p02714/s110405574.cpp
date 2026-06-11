#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	string S;
	cin >> N >> S;
	long long R = 0;
	long long G = 0;
	long long B = 0;
	for (int n = 0; n < S.size(); ++n) {
		if ('R' == S[n]) {
			++R;
		}
		else if('G'==S[n]){
			++G;
		}
		else {
			++B;
		}
	}
	//cout << R<<G<<B << endl;
	long long ans = R * G * B; 
	//cout << ans << endl;
	for (int i = 0;i<N;++i) {
		for (int j = i+1;j<N;++j) {
			int k = 2 * j - i;
			if (k >= N) {
				continue;
			}
			if (S[i]==S[j]) {
				continue;
			}
			if (S[i]==S[k]) {
				continue;
			}
			if (S[j]==S[k]) {
				continue;
			}
			--ans;
		}
	}
	cout << ans <<endl; 
	return 0;
}