#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << # x << "; "<< x << endl


int main() {
	int N;
	string S;
	cin >> N >> S;

	for (int i = 0; i < N / 2; i++) {
		if (N % 2 == 1) {
			cout << "No" << endl;
			break;
		}
		 else if (S.at(i) == S.at(N / 2 + i) && i + 1 < N / 2) {
			continue;
		}
		else if (S.at(i) == S.at(N / 2 + i) && i + 1 == N / 2) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
			break;
		}
		}
	if (N == 1) {
		cout << "No" << endl;
	}
	}
