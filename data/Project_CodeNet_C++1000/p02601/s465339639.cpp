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
	int a, b, c;
	cin >> a >> b >> c;
	int k;
	cin >> k;
	ll cnt(0);
	while (1) {
		if (a >= b) {
			b *= 2;
			cnt++;
		}
		else if (c <= b) {
			c *= 2;
			cnt++;
		}
		else {
			break;
		}
	}
	if (cnt <= k) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}