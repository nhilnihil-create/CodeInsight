#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>

int main() {
	int n;
	cin >> n;
	vector<int>a(n+1);
	vector<int>b(n + 1);
	rep(i, n) {
		cin >> a[i+1];
	}
	int ans;
	for (int i = n; i > 0; --i) {
		int cnt(0);
		for (int j = i * 2; j <= n;j+=i) {
			cnt += b[j];
			
		}
		//cout << cnt << " ";
		if (cnt % 2 != a[i]) {
			b[i]++;
		}
		
	}
	ans = 0;
	rep(i, n+1) {
		ans += b[i];
	}
	
	cout << ans << endl;
	for (int i = 1; i <= n; ++i) {
		if (!b[i])continue;
		cout << i << " ";
	}
	return 0;
}