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
typedef priority_queue<int> PQ;
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
#define LLINF 7223372036854775807
#define mod 1000000007
//vector<vector<int> > dp;
//vector<vector<vector<int> > > vvvi;
//dp=vector<vector<int> >(N, vector<int>(M,0));
//vector<pair<int,int> > v;
//v.push_back(make_pair(x,y));
//priority_queue<int,vector<int>, greater<int> > q2;



signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	VI H(N + 1, 0);
	REP(i, N)cin >> H[i + 1];

	int dp[310][310];
	REP(i, 310) {
		REP(j, 310)dp[i][j] = LLINF;
	}
	//x番目まで見た時にy個選んだ時
	dp[0][0] = 0;
	
	eFOR(i, 1, N) {
		dp[i][0] = dp[i - 1][0] + max(0LL, H[i] - H[i - 1]);
		//cout << dp[i][0] << " ";
	}
	eFOR(i,1, N) {
		eFOR(j, 1, N - K) {

			int next = LLINF;

			FOR(k, 0, i) {
				next = min(next, dp[k][j - 1] + max(0LL, H[i] - H[k]));
			}

			dp[i][j] = min(dp[i][j], next);
		}
	}



	int ans = LLINF;
	eREP(i, N) {
		ans = min(ans, dp[i][N - K]);
	}
	cout << ans << endl;
	return 0;
}

