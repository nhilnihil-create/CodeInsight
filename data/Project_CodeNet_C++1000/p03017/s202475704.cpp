
// A - Kenken Race

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;
	A--;
	B--;
	C--;
	D--;

	string S;
	cin >> S;

	bool possible = true;

	for (int i=A; i<=C-2; i++) {
		if (S[i+1] == '#' && S[i+2] == '#') possible = false;
	}

	for (int i=B; i<=D-2; i++) {
		if (S[i+1] == '#' && S[i+2] == '#') possible = false;
	}

	if (C > D) {
		bool can_overtake = false;
		for (int i=B; i<=D; i++) {
			if (S[i-1] == '.' && S[i+1] == '.') {
				can_overtake = true;
			}

			if (S[i+1] == '#') i++;
		}

		if (can_overtake == false) possible = false;
	}

	string ans;
	if (possible) ans = "Yes";
	else ans = "No";

	cout << ans << endl;

	return 0;
}