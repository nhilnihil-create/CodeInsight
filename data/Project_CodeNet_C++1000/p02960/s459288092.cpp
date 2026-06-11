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
//#define mod 13
#define mod 1000000007
//priority_queue<int,vector<int>, greater<int> > q2;



signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string S;
	cin >> S;
	int N = S.size();
	reverse(S.begin(), S.end());
	int ten = 1;
	//int dp[100010][13] = { 0 };
	vector<VI>dp(N + 1, VI(13, 0));
	dp[0][0] = 1;

	REP(i, N) {
		if (S[i] != '?') {
			int a = S[i] - '0';
			a = a * ten%13;
			REP(j, 13) {
				dp[i + 1][(j + a) % 13] += dp[i][j];
				dp[i + 1][(j + a) % 13] %= mod;
			}
		}
		else {
			REP(k, 10) {
				int a = k;
				a = a * ten%13;
				REP(j, 13) {
					dp[i + 1][(j + a) % 13] += dp[i][j];
					dp[i + 1][(j + a) % 13] %= mod;
				}
			}
		}
		

		ten *= 10;
		ten %= 13;
	}
	//cout << dp[1][5] << endl;
	//cout << dp[2][5] << endl;
	cout << dp[N][5] << endl;
	return 0;
}

