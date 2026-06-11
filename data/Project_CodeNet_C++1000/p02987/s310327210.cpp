#include <bits/stdc++.h>

using namespace std;

int main() {

	string S; cin >> S;
	sort(S.begin(), S.end());
	map<char, int> letters;
	// for (int i = 0; i < 4; i++) {
	// 	letters[S[i]] = 0;
	// }
	for (int i = 0; i < 4; i++) {
		letters[S[i]] += 1;
	}
	for (const auto& letter : letters) {
		if (letter.second > 2 || letter.second < 2)  {
			cout << "No"; 
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}