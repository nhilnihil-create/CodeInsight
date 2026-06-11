#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	string S;
	cin >>N >>S;
	string ansS;
	for (int n = 0; n < S.size(); ++n) {
		int num = S[n] - 'A';
		num += N;
		num %= 26; 
		ansS += 'A' + num;
	}
	cout << ansS <<endl;
	return 0;
}