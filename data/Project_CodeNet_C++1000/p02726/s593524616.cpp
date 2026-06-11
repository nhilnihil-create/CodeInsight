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
const int INF = 1e9;
int m[3000];

int main() {
	int n, x, y;
	cin >> n >> x >> y;
	x--;
	y--;
	rep(i, n)rep(j, n) {
		if (i == j)continue;
		int k = min(abs(j - i), min(abs(x - i) + abs(y - j) + 1,abs(i-y)+abs(j-x)+1));
		k--;
		m[k]++;
	}
	rep(i, n-1) {
		cout << m[i] / 2 << endl;
	}
	return 0;
	
}