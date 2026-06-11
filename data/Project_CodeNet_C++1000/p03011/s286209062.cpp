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
	int p, q, r;
	cin >> p >> q >> r;
	int ans = p + q + r;
	int m = max(p, max(q, r));
	cout << ans - m;
	return 0;
}