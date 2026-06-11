#include "bits/stdc++.h"

using namespace std;
int main() {
	int N;
	cin >> N;
	set<int>S;
	for (int n = 0;n<N;++n) {
		int num;
		cin >> num;
		S.insert(num);
	}
	if (N == S.size()) {
		cout <<"YES"<<endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}
