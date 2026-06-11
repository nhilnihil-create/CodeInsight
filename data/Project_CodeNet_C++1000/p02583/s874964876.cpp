#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {

	int n;
	cin >> n;
	vector<int> l(n);
	for (int i = 0; i < n; i++) cin >> l[i];

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (i < j && j < k) {
					if (l[i] == l[j] || l[j] == l[k] || l[k] == l[i]) continue;
					if ((long long)l[i] + l[j] + l[k] <= max({ l[i],l[j],l[k] }) * 2) continue;
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}