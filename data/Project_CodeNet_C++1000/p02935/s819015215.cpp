#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n; cin >> n;
	vector<double> v(n);
	for (int i = 0; i < n; i++) cin >> v.at(i);
	sort(v.begin(), v.end());

	for (int i = 1; i < n; i++) v.at(i) = (v.at(i - 1) + v.at(i)) / 2;
	cout << v.at(n - 1) << endl;
}