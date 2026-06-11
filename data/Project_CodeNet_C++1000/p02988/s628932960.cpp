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
	vector<int>p(n);
	rep(i, n) {
		cin >> p[i];
	}
	int cnt(0);
	rep(i, n) {
		if (i + 2 > n - 1)continue;
		if (p[i] < p[i + 1] && p[i + 1] < p[i + 2])cnt++;
		if (p[i] > p[i + 1] && p[i + 1] > p[i + 2])cnt++;
	}
	cout << cnt;
	return 0;
}