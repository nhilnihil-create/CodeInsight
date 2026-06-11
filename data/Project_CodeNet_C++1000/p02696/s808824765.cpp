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
	int a, b, n;
	cin >> a >> b >> n;
	cout << (a * min(n, b-1)) / b - a * (min(n, b-1) / b);
}
	