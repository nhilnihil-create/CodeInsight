#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << # x << "; "<< x << endl


int main() {
	int K;
	string S;
	cin >> K >> S;
	vector<string> vec(K);
	if (S.size() <= K) {
		cout << S << endl;
	}
	else if (S.size() > K) {
		for (int i = 0; i < K; i++) {
			cout <<S.at(i);
		}
		cout << "..." << endl;
	}
}