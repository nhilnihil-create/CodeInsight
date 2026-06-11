#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;
typedef long long ll;
#define int long long
#define double long double
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef vector<pii> VP;
typedef vector<string> VS;
typedef priority_queue<int> PQ;
template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
#define fore(i,a) for(auto &i:a)
#define REP(i,n) for(int i=0;i<n;i++)
#define eREP(i,n) for(int i=0;i<=n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define eFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define SORT(c) sort((c).begin(),(c).end())
#define rSORT(c) sort((c).rbegin(),(c).rend())
#define LB(x,a) lower_bound((x).begin(),(x).end(),(a))
#define UB(x,a) upper_bound((x).begin(),(x).end(),(a))
#define INF 1000000000
#define LLINF 9223372036854775807
#define mod 1000000007
#define eps 1e-12 
//priority_queue<int,vector<int>, greater<int> > q2;

bool solve(int N, int K) {
	if (N == 1)return true;
	if (N < K)return false;
	if (N%K == 0)return solve(N / K, K);
	return solve(N%K, K);

}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N; cin >> N;
	int n = N;
	vector<int> ret;
	map<int, bool>mp;
	for (int i = 1; i*i <= n; ++i)
	{
		if (n%i == 0)
		{
			if (!mp[i]) {
				ret.push_back(i);
				mp[i] = 1;
			}
			if (i*i != n)
			{
				if (!mp[n / i]) {
					ret.push_back(n / i);
					mp[n / i] = 1;
				}
			}
		}
	}
	n = N - 1;
	for (int i = 1; i*i <= n; ++i)
	{
		if (n%i == 0)
		{
			if (!mp[i]) {
				ret.push_back(i);
				mp[i] = 1;
			}
			if (i*i != n)
			{
				if (!mp[n / i]) {
					ret.push_back(n / i);
					mp[n / i] = 1;
				}
			}
		}
	}
	SORT(ret);
	int ans = 0;
	fore(i, ret) {
		if (i == 1)continue;
		if (solve(N, i))ans++;
	}

	cout << ans << endl;

	return 0;
}

