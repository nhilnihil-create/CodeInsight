#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<string>
#include<queue>
#include<iomanip>
#include<bitset>
#include<math.h>
#include<stack>
#include<set>
using namespace std;
#define int long long
int mod = 1e9 + 7;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	int n, k;
	cin >> n >> k;
	int r = 0;
	for (int i = k; i <= n+1; i++) {
		r += (n+1) * (n + 2) / 2 - (n+1 - i) * (n+1 - i + 1) / 2 - i*(i+1)/2+1;
		r %= mod;
	}
	cout << r << endl;
}
	