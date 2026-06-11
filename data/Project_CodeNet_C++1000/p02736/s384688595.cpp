#include <iostream>
#include <string>
using namespace std;

int val[1 << 20];

void init() {
	for (int i = 1; i <= 1000000; i++) {
		int cx = i;
		while (cx % 2 == 0) { cx /= 2; val[i]++; }
	}
}

bool solve(string S) {
	int r = 0, cnt = 0;
	for (int i = 0; i < S.size(); i++) {
		if (r == 0) cnt += (S[i] - '0');
		r -= val[i + 1];
		r += val[S.size() - i - 1];
	}
	if (cnt % 2 == 0) return false;
	return true;
}

int main() {
	int N; string S; cin >> N >> S; init();
	bool I = solve(S);
	if (I == true) {
		cout << "1" << endl;
	}
	else {
		bool flag = false;
		for (int i = 0; i < S.size(); i++) {
			if (S[i] == '2') flag = true;
		}
		if (flag == true) { cout << "0" << endl; }
		else {
			string T = "";
			for (int i = 0; i < S.size() - 1; i++) {
				if (S[i] == S[i + 1]) T += "0";
				else T += "1";
			}
			bool J = solve(T);
			if (J == true) cout << "2" << endl;
			else cout << "0" << endl;
		}
	}
	return 0;
}