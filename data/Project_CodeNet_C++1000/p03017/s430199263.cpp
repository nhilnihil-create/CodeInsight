#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;
	A--; B--; C--; D--;
	string S;
	cin >> S;
	char now = '.';
	bool p = true;
	for (int i = A; i < C; i++) {
		if (S[i] == '#' && now == '#') p = false;
		now = S[i];
	}
	now = '.';
	for (int i = B; i < D; i++) {
		if (S[i] == '#' && now == '#') p = false;
		now = S[i];
	}

	if (C > D) {
		p = false;
		for (int i = B; i <= D; i++) {
			if (S[i-1]=='.' && S[i]=='.' && S[i+1]=='.') p = true;
		}
	}

	if (p) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
