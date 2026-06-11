#include<iostream>
#include<vector>
using namespace std;
int main() {
	int N,K;
	string S;
	cin >> N >> K >> S;
	int rec = 0;
	for (int i = 0; i < N - 1; i++) {
		if (S[i] == S[i + 1]) {
			rec++;
		}
	}
	rec += 2 * K;
	if (rec < S.length()) {
		cout << rec << endl;
	}
	else {
		cout << S.length() - 1 << endl;
	}
	return 0;
}