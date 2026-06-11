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
	int x, n;
	cin >> x >> n;
	vector<int>a(101);
	rep(i, n) {
		int k;
		cin >> k;
		a[k]++;
	}
	//cout << 1;
	rep(i, 100) {
		if (x - i >= 0) {
			if (a[x - i] == 0) {
				cout << x - i;
				return 0;
			}
		}
		if (x + i <= 101) {
			if ( a[x + i] == 0) {
				cout << x + i;
				return 0;
			}
		}
	}
	return 0;
}