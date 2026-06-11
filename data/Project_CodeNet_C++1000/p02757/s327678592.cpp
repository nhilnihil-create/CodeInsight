#include "bits/stdc++.h"
using namespace std;
int main() {
	int N, P;
	string S;
	cin >>N >> P >> S;
	vector<int>NUM(S.size()+1);
	NUM[0] = 0;
	int num = 0;
	int ten = 1;
	for (int n = 0;n<S.size();++n) {
		int m = S[S.size()-1-n] - '0';
		ten *= 10;
		ten %= P;
		num = (ten * m + num)%P;
		NUM[n+1] = num; 
		//cout << NUM[n + 1] << endl;
	}
	long long nans = 0;
	if (2 == P ||5 == P) {
		for (int n = 0; n < S.size(); ++n) {
			int m = S[n] - '0';
			if (0 == m%P) {
				nans += (n + 1);
			}
		}
	}
	else {
		vector<long long>MOD(P);
		for (int n = 0; n < S.size() + 1; ++n) {
			MOD[NUM[n]]++;
		}
		for (int n = 0; n < P; ++n) {
			nans += (MOD[n] - 1) * MOD[n] / 2;
		}
	}
	cout << nans<< endl;
	return 0;
}