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

template <typename T>
struct PrimeFact {
	vector<T> spf;
	PrimeFact(T N) { init(N); }
	void init(T N) { // 前処理。spf を求める
		spf.assign(N + 1, 0);
		for (T i = 0; i <= N; i++) spf[i] = i;
		for (T i = 2; i * i <= N; i++) {
			if (spf[i] == i) {
				for (T j = i * i; j <= N; j += i) {
					if (spf[j] == j) {
						spf[j] = i;
					}
				}
			}
		}
	}
	map<T, T> get(T n) { // nの素因数分解を求める
		map<T, T> m;
		while (n != 1) {
			m[spf[n]]++;
			n /= spf[n];
		}
		return m;
	}
};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n; cin >> n;
	int ans = 0;
	FOR(i, 1, n) {
		int N = n - i;
		int l = 2;
		VI so, shi;
		while (l*l <= N) {
			int cnt = 0;
			while (N%l == 0) {
				cnt++;
				N /= l;
			}
			if (cnt > 0) {
				shi.push_back(cnt);
				so.push_back(l);
			}
			l++;
		}
		if (N != 1) {
			shi.push_back(1);
			so.push_back(l);
		}
		int tmp = 1;
		REP(j, shi.size()) {
			tmp *= (shi[j] + 1);
			//cout << tmp << endl;
			//cout << so[j] << " " << shi[j] << endl;
		}
		ans += tmp;
	}
	cout << ans << endl;
	return 0;
}

