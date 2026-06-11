#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int>x(n), y(n);
	for (int i = 0; i < n; i++)cin >> x[i] >> y[i];
	
	vector<int>g; for (int i = 0; i < n; i++)g.push_back(i);
	vector<vector<int>>inorder;
	do {
		inorder.push_back(g);
	} while (next_permutation(g.begin(), g.end()));

	double ans = 0;
	for (int i = 0; i < inorder.size(); i++) {
		for (int j = 0; j < n - 1; j++) {
			double xi, yi;
			xi = x[inorder[i][j]] - x[inorder[i][j + 1]];
			yi = y[inorder[i][j]] - y[inorder[i][j + 1]];
			ans += sqrt(xi * xi + yi * yi);
		}
	}
	printf("%.10f", ans/inorder.size());

	return 0;
}