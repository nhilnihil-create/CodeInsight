#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
	int n, k, p[1000], ans = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	sort(p, p + n);
	for (int i = 0; i < k; i++) {
		ans += p[i];
	}
	cout << ans << endl;
	return 0;
}