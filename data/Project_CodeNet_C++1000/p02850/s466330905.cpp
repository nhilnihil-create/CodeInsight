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

int N;
VI G[100010];


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	int K = -1;
	VI ans(N - 1);
	map<pii, int>mp;
	REP(i, N - 1) {
		int a,b; cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
		chmax(K, (int)G[a].size());
		chmax(K, (int)G[b].size());
		mp[pii(a, b)] = mp[pii(b, a)] = i;
	}

	queue<int>Q;
	Q.push(0);
	vector<bool>vis(N, false);
	vis[0] = 1;
	vector<VI>no(N);

	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		int co = 1;
		fore(to, G[now]) {

			if (vis[to])continue;
			//if ((no[now].size() > 0 && no[now][0] != co) || no[now].empty()) {
			if (no[now].size() > 0 && no[now][0] == co) co++;
				ans[mp[pii(now, to)]] = co;
				Q.push(to);
				vis[to] = 1;
				no[to].push_back(co);
			
			co++;
		}
	}



	cout << K << endl;
	REP(i, N - 1)cout << ans[i] << endl;

	return 0;
}

