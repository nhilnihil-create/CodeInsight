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
typedef priority_queue<pii> PQ;
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



signed main() {
cin.tie(0);
ios::sync_with_stdio(false);

	int N;
	cin >> N;
	VI A(N), B(N);
	PQ Q;
	REP(i, N)cin >> A[i];
	REP(i, N) {
		cin >> B[i];
		Q.push(pii(B[i], i));
	}
	//   i-j-k
	int ans = 0;
	while (!Q.empty()) {
		//REP(a, N)cout << B[a] << " ";
		//cout << endl;
		//ans++;
		int a = Q.top().first, j = Q.top().second;
		Q.pop();
		int i = j - 1, k = j + 1;
		if (j == 0)i = N - 1;
		if (j == N - 1)k = 0;

		if (B[j] == A[j])continue;
		if (B[j] < A[j]) {
			cout << -1 << endl;
			return 0;
		}

		int x = (B[i] + B[k]);
		int K = (B[j] - A[j]) / x;
		
		if (K==0) {
			cout << -1 << endl;
			return 0;
		}
		ans += K;
		B[j] -= x*K;
		
		Q.push(pii(B[j],j));
	}
	bool F = true;
	REP(i, N)if (A[i] != B[i])F = false;
	cout << (F ? ans : -1) << endl;

	return 0;
}

