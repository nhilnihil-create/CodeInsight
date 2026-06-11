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

int dp[3010][3010];

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, T; cin >> N >> T;
	VP A(N);
	REP(i, N)cin >> A[i].first >> A[i].second;
	SORT(A);

	REP(i, N) {
		int t = A[i].first, v = A[i].second;
		eREP(j, T) {
			int nj = j + t;
			chmin(nj, T);
			if (j != 0)chmax(dp[i + 1][j], dp[i + 1][j - 1]);

			chmax(dp[i + 1][j], dp[i][j]);
			if(j!=T)chmax(dp[i + 1][nj], dp[i][j] + v);
		}
	}
	cout << dp[N][T] << endl;

	return 0;
}

