#include <bits/stdc++.h> 
using namespace std;

int main() {
	string S, T;
	int ans = 0;
	cin >> S;
	cin >> T;

	for (unsigned int i = 0; i < S.size(); i++) {
		if (S.at(i) != T.at(i)) ans++;
	}

	cout << ans << endl;
	return 0;
}