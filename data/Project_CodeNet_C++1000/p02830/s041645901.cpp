#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << # x << "; "<< x << endl


int main() {
	int N;
	string S, T;
	cin >> N >> S >> T;
	vector<string> vec(2 * N);
	for (int i = 0; i < 2 * N; i++) {
		if (i % 2 == 0) {
			vec.at(i) = S.at(i / 2);
		}
		else {
			vec.at(i) = T.at(i / 2);
		}
	}
	for (int j = 0; j < 2 * N; j++) {
		cout << vec.at(j);
	}
}