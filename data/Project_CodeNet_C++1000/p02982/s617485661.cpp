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
	int n, d;
	cin >> n >> d;
	vector<vector<int>>x(n, vector<int>(d));
	rep(i, n) {
		rep(j, d) {
			cin >> x[i][j];
		}
	}
	int ans(0);
	rep(i, n) {
		rep(j, n) {
			int sum(0);
			if (i == j)continue;
			rep(k, d) {
				sum += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
			}
			int root = sqrt(sum);
			if (root * root == sum) {
				ans++;
			}
		}
	}
	cout << ans / 2;
	return 0;

}