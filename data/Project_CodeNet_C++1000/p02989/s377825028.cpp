#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int diff[100010];
int main() {
	int n;
	cin >> n;
	rep(i, n) {
		cin >> diff[i];
	}
	sort(diff, diff + n);
	int left = diff[n/2-1];
	int right = diff[n/2];
	cout << right - left << endl;
	return 0;
}