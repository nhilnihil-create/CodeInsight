#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	vector<pair<int, int>> pa;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		pa.push_back({ a,i + 1 });
	}
	sort(pa.begin(), pa.end());
	for (int i = 0; i < pa.size(); i++) {
		cout << pa[i].second << " ";
	}
	cout << endl;
	return 0;
}