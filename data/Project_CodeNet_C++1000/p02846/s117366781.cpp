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

	int T1, T2, A1, A2, B1, B2;
	cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;

	A1 *= T1;
	A2 *= T2;
	B1 *= T1;
	B2 *= T2;
	A2 += A1;
	B2 += B1;
	if (A2 == B2) {
		cout << "infinity" << endl;
		return 0;
	}
	if (A2 < B2) {
		swap(A1, B1);
		swap(A2, B2);
	}
	int D = A2 - B2;
	int C = B1 - A1;

	int ans = 0;
	if (C > 0) {
		ans = (C - 1) / D + 1;
		ans *= 2;
		ans--;
		if (C%D == 0)ans++;
	}

	cout << ans << endl;

	return 0;
}

