#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << # x << "; "<< x << endl


int main() {
	string S, T;
	int total;
	total = 0;
	cin >> S >> T;
	for (int i = 0; i < S.size(); i++) {
		if (S.at(i) != T.at(i)) {
			total += 1;
		}
		else if (S.at(i) == T.at(i)) {
			continue;
		}
	}
	cout << total << endl;
}