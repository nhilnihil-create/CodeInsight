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
//vector<vector<int> > dp;
//vector<vector<vector<int> > > vvvi;
//dp=vector<vector<int> >(N, vector<int>(M,0));
//vector<pair<int,int> > v;
//v.push_back(make_pair(x,y));
//priority_queue<int,vector<int>, greater<int> > q2;

int divceil(int a, int b) {
	return (a + b - 1) / b;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int K, P;
	cin >> K >> P;
	VI D(K);
	REP(i, K)cin >> D[i];

	REP(i, P) {
		int N, X, M;
		cin >> N >> X >> M;

		int L = X, E = 0;
		REP(i, K) {
			int num = divceil(N - 1 - i, K);
			L += (D[i] % M)*num;
			if (D[i] % M == 0)E += num;
		}
		int ans = (N - 1) - (L / M - X / M) - E;
		cout << ans << endl;
	}



	return 0;
}

