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
#define mod 1000000007
//priority_queue<int,vector<int>, greater<int> > q2;

int N, K;
VI G[100010];
int cnt[100010];
int ans = 1;

void dfs(int now, int pa) {
	int tmp = 0;
	if (pa != -1) {
		tmp = cnt[pa] + 1;
	}
	//cout << now << " " << tmp << endl;
	if (K - tmp <= 0) {
		ans = 0;
		//cout << "L" << endl;
		return;
	}

	ans *= (K - tmp);
	ans %= mod;
	if (pa != -1)cnt[pa]++;
	fore(to, G[now]) if (to != pa) {
		cnt[to]++;
		dfs(to, now);
	}
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	cin >> N >> K;
	REP(i, N - 1) {
		int a, b; cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(0, -1);

	cout << ans << endl;

	return 0;
}

