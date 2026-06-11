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
signed main() {
	int n;
	cin >> n;
	if (log2(n) == (int)log2(n))puts("No");
	else {
		puts("Yes");
		cout << 1 + n << " " << 2 + n << endl;
		for (int i = 2; i < n; i += 2) {
			cout << 1 << " " << i << endl;
			cout << i << " " << i + 1 << endl;
			cout << 1 << " " << n + i + 1 << endl;
			cout << n + i << " " << n + i + 1 << endl;
		}
		if (n % 2 == 0) {
			int m = n ^ 1;
			for (int i = 2; i < n; i++) {
				if ((m ^ i) < n) {
					cout << n << " " << i << endl;
					cout << 2 * n << " " << (m ^ i) + n << endl;
					break;
				}
			}
		}
	}
	return 0;
}