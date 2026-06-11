#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
#define int long long
using namespace std;
const int INF = 1000000000;
const int mod = 1000000007;
signed main() {
	int n, x = 0, y = 0; cin >> n;
	if (n == 1000000000000000000) {
		cout << 0 << ' ' << 0 << ' ' << INF << ' ' << 0 << ' ' << 0 << ' ' << INF << endl;
		return 0;
	}
	x = (n / INF + 1) * INF - n; y = (n + x) / INF;
	cout << 0 << ' ' << 0 << ' ' << INF << ' ';
	cout << 1 << ' ' << x << ' ' << y << endl;
	return 0;
}