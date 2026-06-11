#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

int main(void) {
	string S, T;
	cin >> S >> T;
	bool ans = true;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] != T[i]) {
			ans = false;
			break;
		}
	}
	printf(ans ? "Yes" : "No");

	return 0;
}
