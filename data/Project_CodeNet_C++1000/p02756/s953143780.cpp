#include"bits/stdc++.h"

#define rep(i, N) for(int i = 0;i < N;i++)

typedef long long ll;

const int mod = 1e9 + 7;

using namespace std;



int main(void) {
	string S; cin >> S;
	int Q; cin >> Q;

	int inv = 0;

	rep(hoge, Q) {
		int T; cin >> T;
		if (T == 1) {
			inv = (inv + 1) % 2;
		}
		else {
			int F; char C; cin >> F >> C;
			F--;
			if ((inv+F)%2==0) {
				S.insert(S.begin(), C);
			}
			else {
				S.push_back(C);
			}
		}
	}

	if (inv == 1) {
		reverse(S.begin(), S.end());
	}

	cout << S << endl;

	return 0;
}