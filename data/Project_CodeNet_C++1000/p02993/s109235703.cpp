#include <bits/stdc++.h>

using namespace std;

int main() {
	string S; cin >> S;

	// bool strong = true;
	for (int i = 1; i < S.size(); i++)
		if (S[i - 1] == S[i]) { cout << "Bad"; return 0;}
	cout << "Good";
	return 0;
}