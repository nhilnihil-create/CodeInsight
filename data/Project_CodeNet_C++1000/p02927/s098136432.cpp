#include <iostream>
#include<vector>
#include<algorithm>
#include <queue>
#include <string>
#include <set>
using namespace std;
#define ff(i,n,m) for(int i=n;i<m;i++)
#define i64 int64_t

int main() {
	int m, d;
	cin >> m >> d;
	int ans = 0;
	ff(i, 4, m + 1) {
		ff(j, 22, d + 1) {
			if (j % 10 < 2) {
				continue;
			}
			if ((j / 10) * (j % 10) == i) {
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}