#include "bits/stdc++.h"
using namespace std;
int main() {
	int N;
	cin >> N;
	set<string>S;
	for (int n = 0;n<N;++n) {
		string str;
		cin >> str;
		S.insert(str);
	}

	cout << S.size() <<endl;
	return 0;
}