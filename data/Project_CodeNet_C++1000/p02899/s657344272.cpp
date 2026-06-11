#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,tmp;
	vector<pair<int,int>> a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		a.push_back(make_pair(tmp,i));
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		cout << a.at(i).second+1;
		if (i != n - 1) {
			cout << " ";
		}
	}
	cout << endl;
}