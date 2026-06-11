#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <functional>
#include <map>
#include <math.h>
#include <list>

using namespace std;
#define ll long long int


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> a;
	int sum = 0;
	int n, m;
	int in;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> in;
		a.push_back(in);
		sum += in;
	}
		sort(a.begin(), a.end(), greater<int>());

		if (a[m - 1] * 4 * m >= sum) cout << "Yes" << endl;
		else cout << "No" << endl;

	return 0;
}
