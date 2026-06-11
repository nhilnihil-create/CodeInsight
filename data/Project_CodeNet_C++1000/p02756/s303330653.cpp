#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	string S;
	int Q;
	cin >> S >> Q;
	string front, back;
	bool reverse = false;
	for(int i = 0; i < Q; i++) {
		int T;
		cin >> T;
		if(T == 1)
			reverse = !reverse;
		else {
			int F;
			string C;
			cin >> F >> C;
			if(F == 1) {
				if(!reverse)
					front += C;
				else
					back += C;
			} else {
				if(!reverse)
					back += C;
				else
					front += C;
			}
		}
	}
	if(!reverse) {
		for(int i = front.size() - 1; i >= 0; i--) cout << front[i];
		cout << S << back;
	} else {
		for(int i = back.size() - 1; i >= 0; i--) cout << back[i];
		for(int i = S.size() - 1; i >= 0; i--) cout << S[i];
		cout << front;
	}
	return 0;
}
