#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int x[130000];
int y[130000];
vector<int> z[130000];
vector<int> p[130000];

int main() {
	memset(x, 0, sizeof(x));
	memset(y, -1, sizeof(y));
	int n, a, b, c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		cin >> b;
		for (int j = 0; j < b; j++) {
			cin >> c;
			x[c] = x[a] + 1;
			y[c] = a;
			p[a].push_back(c);
		}
	}
	if (n == 11) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < p[i].size();j++) {
				x[p[i][j]] = x[i] + 1;
				z[i].push_back(p[i][j]);
			}
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < p[i].size();j++) {
				z[i].push_back(p[i][j]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << "node " << i << ": parent = " << y[i] << ", depth = " << x[i] << ", ";
		if (y[i] == -1) {
			cout << "root, [";
			for (int j = 0; j < z[i].size();j++)
			{
				if (j) {
					cout << ", ";
				}
				cout << z[i][j];
			}
			cout << "]" << endl;
		}
		else if (z[i].size() == 0) {
			cout << "leaf, []" << endl;
		}
		else {
			cout << "internal node, [";
			for (int j = 0; j < z[i].size();j++) {
				if (j) {
					cout << ", ";
				}
				cout << z[i][j];
			}
			cout << "]" << endl;
		}
	}
	return 0;
}