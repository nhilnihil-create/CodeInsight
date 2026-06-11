#include <bits/stdc++.h>
using namespace std;

int main() {
	int k, x;
	cin >> k >> x;

	vector<int> ans;
    for (int i = x; i < k + x; i++) {
    	ans.push_back(i);
    }

    for (int i = x - 1; i > x - k; i--) {
    	ans.push_back(i);
    }

    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
    	cout << ans[i] << " ";
    }
    return 0;
}