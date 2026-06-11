#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	long long int n, k;
	cin >> n >> k;
	vector<long long int>h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	if (n <= k) {
		cout << 0 << endl;
		return 0;
	}
	long long int ans=0;
	sort(h.rbegin(), h.rend());
	for (int i = k; i < n; i++) {
		ans = ans + h[i];
	}
	cout << ans << endl;
}