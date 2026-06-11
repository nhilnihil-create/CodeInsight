#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	vector<int>k = { 1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51 };
	int n;
	cin >> n;
	cout << k.at(n - 1) << endl;
}