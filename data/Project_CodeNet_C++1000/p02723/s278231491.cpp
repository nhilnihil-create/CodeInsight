#include<cstdio>
#include<iostream>
using namespace std;

int main(void) {
	string S;
	cin >> S;
	bool ans = true;
	if (S[2] != S[3]) ans = false;
	if (S[4] != S[5]) ans = false;
	printf(ans ? "Yes" : "No");

	return 0;
}
