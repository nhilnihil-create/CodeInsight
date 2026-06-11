#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a;
	vector<int> A;
	vector<vector<int>> AA;
	cin >> n;
	bool check[100] = { 1 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> a;
			A.push_back(a);
		}
		AA.push_back(A); A.clear();
	}
	for (int i = 0; i < AA.size(); i++) {
		int b = 0, c = 0; check[i] = 1;
		for (int j = 0; j < AA[i].size(); j++) {
			if (b >= c) {
				if (AA[i][j] > b)b = AA[i][j];
				else {
					if (AA[i][j] > c)c = AA[i][j];
					else {
						check[i] = 0; break;
					}
				}
			}
			else {
				if (AA[i][j] > c)c = AA[i][j];
				else {
					if (AA[i][j] > b)b = AA[i][j];
					else {
						check[i] = 0; break;
					}
				}
			}
		}
	}
	for (int i = 0; i < AA.size(); i++) {
		if (check[i])cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}