#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	int n;
	cin >> n;
	vector<int> w(n);

	int sum = 0;
	rep(i, n){
		cin >> w.at(i);
		sum += w.at(i);
	}

	int diff = sum;
	int totyu = 0;
	rep(i, n){
		totyu += w.at(i);
		diff = min(diff, abs(totyu - (sum - totyu)));
	}

	cout << diff << endl;
	return 0;
}