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
	vector<int>a(n);
	rep(i, n) {
		cin >> a[i];
	}
	ll ans(0);
	rep(i, n) {
		ans ^= a[i];
	}
	//vector<int>an(n);
	rep(i, n) {
		a[i] ^= ans;
		cout << a[i] << endl;
	}
	return 0;
}