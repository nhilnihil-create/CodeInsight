#include <iostream>
#include <vector>
using namespace std;

int n = 0, id = 0, k = 0;
vector<int> d, p;

int depth(int id) {
	if (p[id] == -1)
		return 0;
	else if (d[p[id]] != -1)
		return d[p[id]] + 1;
	else
		return depth(p[id]) + 1;
}

int main()
{	
	cin >> n;

	vector<vector<int>> c(n);

	for (int i = 0; i < n; i++) {
		p.push_back(-1);
		d.push_back(-1);
	}

	for (int i = 0; i < n; i++) {
		cin >> id >> k;

		for (int j = 0; j < k; j++) {
			int ct = 0;
			cin >> ct;
			c[id].push_back(ct);
			p[ct] = id;
		}
	}

	for (int i = 0; i < n; i++) {
		d[i] = depth(i);
	}

	for (int i = 0; i < n; i++) {
		cout << "node " << i << ": parent = " 
			 << p[i] << ", depth = " << d[i] << ", ";

		if (p[i] == -1)
			cout << "root, ";
		else if (c[i].size() == 0)
			cout << "leaf, ";
		else
			cout << "internal node, ";

		cout << "[";
		if (c[i].size() > 1) {
			for (unsigned int j = 0; j < c[i].size() - 1; j++)
				cout << c[i][j] << ", ";
		}
		if (c[i].size() >= 1)
			cout << c[i][c[i].size() - 1];

		cout << "]" << endl;
	}

	return 0;
}