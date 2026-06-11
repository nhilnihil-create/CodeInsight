#include<iostream>
using namespace std;
int main() {
	string S;
	cin >> S;
	int ans = 0;
	for (int i = 0; i < S.length() - 1; i++) {
		if (S[i] == S[i + 1]) {
			ans++;
		}
	}
	if (ans == 0) {
		cout << "Good" << endl;
	}
	else {
		cout << "Bad" << endl;
	}
	return 0;
}