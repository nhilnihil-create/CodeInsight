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

int modpow(int a, int p) {
	if (p == 0) return 1;
	if (p % 2 == 0) {

		int halfP = p / 2;
		int half = modpow(a, halfP);

		return half * half % mod;
	}
	else {

		return a * modpow(a, p - 1) % mod;
	}
}



signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int K, N; cin >> N >> K;

	int ans = 0;

	VI memo(K + 1, 0);

	for (int i = K; i > 0; i--) {
		int a = modpow(K / i, N);

		int j = 2;
		while (j*i<=K) {
			a -= memo[j*i];
			a = (a + mod) % mod;
			j++;
		}


		int cnt = a * i%mod;
		memo[i] = a;
		ans = (ans + cnt) % mod;;
	}

	

	cout << ans << endl;
	return 0;
}

