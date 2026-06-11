#include<iostream>
using namespace std;
int main() {
	string S;cin >> S;char prev = S[0];bool skip = false;
	int ans = S.length();
	for (int i = 1; i < S.length(); i++) {
		if (!skip) {
			if (S[i] == prev) {
				ans--;
				skip = true;
			}
			prev = S[i];
		}else {
			skip = false;
			prev = '0';
		}
	}
	cout << ans;
}