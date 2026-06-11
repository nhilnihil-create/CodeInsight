#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
const int INF = 1 << 30;
const long long MOD = 1000000000 + 7;
const double PI = acos(-1);

int main() {
	vector<int> num(3);
	vector<int> ans;
	rep(i, 3)cin >> num[i];
	rep(i, 3) {
		rep2(j, i + 1, 3) {
			ans.push_back(num[i] + num[j]);
		}
	}
	cout << *min_element(ans.begin(), ans.end());

}