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
	int n, x;
	cin >> n >> x;
	int cnt(1), dd(0);
	rep(i, n) {
		int l;
		cin >> l;
		dd += l;
		if (dd <= x) {
			cnt++;
			
			//cout << dd;
		}
		else {
			break;
		}
	}
	cout << cnt;
	return 0;
}