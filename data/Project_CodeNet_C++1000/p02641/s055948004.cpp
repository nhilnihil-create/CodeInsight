#include<iostream>
#include<vector>
#include<string>
#include<bitset>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<set>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main() {
	int x, n;
	cin >> x >> n;
	vector<int> a(n);
	rep(i, n)
		cin >> a[i];

	vector<int> b(102, 1);
	rep(i, n)
		b[a[i]]--;
	int min = 105;
	int ans;
	for (int i = 101; i >= 0; i--) {
		if (b[i] == 1) {
			if (abs(x - i) <= min) {
				min = abs(x - i);
				ans = i;
			}
		}
	}
	cout << ans << endl;
	return 0;
}