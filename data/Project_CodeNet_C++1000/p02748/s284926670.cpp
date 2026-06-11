#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
using ll = long long;


int main() {
	int A, B, M, ans = INT_MAX;
	cin >> A >> B >> M;
	vector<int> alist(A), blist(B);
	for (int i = 0; i < A; i++) cin >> alist[i];
	for (int i = 0; i < B; i++) cin >> blist[i];
	for (int i = 0; i < M; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		ans = min(ans, alist[x - 1] + blist[y - 1] - c);
	}
	ans = min(ans, *min_element(alist.begin(), alist.end()) + *min_element(blist.begin(), blist.end()));
	cout << ans << endl;

}