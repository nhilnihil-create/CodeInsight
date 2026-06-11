#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	cin >> S;
	sort(S.begin(),S.end());
	if (S[0]!=S[1]) {
		cout << "No" << endl;
		return 0;
	}
	if (S[2]!=S[3]) {
		cout << "No" << endl;
		return 0;
	}
	if (S[1]==S[2]){
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	return 0;
}