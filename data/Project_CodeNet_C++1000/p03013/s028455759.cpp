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
	int N, M;
	cin >> N >> M;
	vector<int>A(M);
	rep(i, M) {
		cin >> A[i];
	}
	set<int>S;
	rep(i, M) {
		S.insert(A[i]);
	}
	vector<int>dp(N+1);
	rep(i, N+1) {
		if (i == 0) {
			dp[i] = 1;
		}
		else if (i == 1) {
			if (S.count(i)) {
				dp[i] = 0;
			}
			else {
				dp[i] = 1;
			}
		}
		else {
			if (S.count(i)) {
				dp[i] = 0;
			}
			else {
				dp[i] = dp[i - 2] + dp[i - 1];
			}
		}
		dp[i] = dp[i] % 1000000007;
	}
	cout << dp[N] << endl;
}