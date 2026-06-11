#include <algorithm>
#include <bitset>
#include <cfloat>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
#define int long long
#define ll long long
#define eps LDBL_EPSILON
#define mod 10000000
#define int long long
#define double long double
#define INF LLONG_MAX/10
#define P pair<int,int>
#define prique priority_queue
using namespace std;
int n, a[200010], ans[200010];
signed main() {
	cin >> n;
	REP(i, n)cin >> a[i];
	for (int i = n; i >= 1; i--) {
		int cnt = 0;
		for (int j = 2 * i; j <= n; j += i)cnt += ans[j];
		if (cnt % 2 != a[i] % 2)ans[i]++;
	}
	vector<int> vec;
	REP(i, n) {
		if (ans[i])vec.push_back(i);
	}
	cout << vec.size() << endl;
	if(!vec.empty())cout << vec[0];
	REP(i, (int)vec.size() - 1)cout << " " << vec[i];
	cout << endl;
	return 0;
}
