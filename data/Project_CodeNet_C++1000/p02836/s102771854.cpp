#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << # x << "; "<< x << endl


int main() {
	string S;
	cin >> S;
	int total = 0;
	for (int i = 0; i < S.size() / 2; i++) {
		if (S.at(i) == S.at(S.size() - 1 - i)) {
			continue;
		}
		else {
			total++;
		}
	}
	cout << total << endl;
}