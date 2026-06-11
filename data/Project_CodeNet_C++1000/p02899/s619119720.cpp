#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>

using namespace std;
typedef long long ll;
typedef double db;
#define inf 0x3f3f3f3f
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int a[112345];
signed main() {
	int n, i, t;
	cin >> n;
	for (i = 1; i <= n; ++i) {
		cin >> t;
		a[t] = i;
	}
	for (i = 1; i <= n; ++i)cout << a[i] << " ";
	cout << endl;
	return 0;
}