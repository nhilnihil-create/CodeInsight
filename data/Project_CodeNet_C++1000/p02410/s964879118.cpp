#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n,m;
	vector<vector<int> > vt;

	vector<int> tmpv;

	int data;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> data;
			tmpv.push_back(data);
		}
		vt.push_back(tmpv);
		tmpv.clear();
	}

	vector<int> bv;

	for (int j = 0; j < m; j++) {
		cin >> data;
		bv.push_back(data);
	}

	int c = 0;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			c += vt[i][j] * bv[j];
		}
		cout << c << endl;
		c = 0;
	}

	return 0;
}