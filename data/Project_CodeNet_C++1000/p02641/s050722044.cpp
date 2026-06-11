#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;

int main() {
	int x, n;
	cin >> x >> n;
	vector<int>p(100,0);
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		p[k]++;
	}
	int i = 0;
	int ans;
	while (1) {
		if (p[x - i] == 0) {
			ans = x - i;
			break;
		}
		else if (p[x + i] == 0) {
			ans = x + i;
			break;
		}
		i++;
	}
	cout << ans;

	return 0;
	
}
