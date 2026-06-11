#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << # x << "; "<< x << endl


int main() {
	string S;
	cin >> S;
	vector<string> X(S.size());
	for (int i = 0; i < S.size(); i++) {
		X.at(i) = "x";
	}
	for (int j = 0; j < S.size(); j++) {
		cout << X.at(j);
	}
}