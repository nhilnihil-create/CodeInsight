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
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n)
		cin >> a[i];

	vector<int> count(1e6 + 1, 0);

	rep(i, n) {
		//cout << "i=" << i << endl; //確認用
		int j=1;
		if (count[a[i] * j] > 0) {
			count[a[i] * j]++;
			continue;
		}
		while (a[i] * j < 1e6 + 1) {
			count[a[i] * j]++;
			j++;
		}
	}
	int ans = 0;
	rep(i, n) {
		if (count[a[i]] == 1)
			ans++;
	}
	
	cout << ans << endl;
	return 0;
}