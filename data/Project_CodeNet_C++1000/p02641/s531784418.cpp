#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<sstream>
#include<iterator>
#include<list>

using namespace std;

#define INF LLONG_MAX / 5
#define int long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define upper(v,hoge) upper_bound(v.begin(),v.end(),hoge)
#define lower(v,hoge) lower_bound(v.begin(),v.end(),hoge)
#define enld endl

signed main() {
	int X, N;
	cin >> X >> N;
	vector<int>P(N);
	rep(i, N) {
		cin >> P[i];
	}
	set<int>S;
	rep(i, N) {
		S.insert(P[i]);
	}
	int m = 100000;
	int ans = 0;
	for (int i = -1000; i <= 1000; i++) {
		if (!S.count(i)) {
			m = min(m, abs(X - i));
		}
	}
	for (int i = -1000; i <= 1000; i++) {
		if (abs(X - i) == m) {
			if (!S.count(i)) {
				cout << i << enld;
				return 0;
			}
		}
	}
}