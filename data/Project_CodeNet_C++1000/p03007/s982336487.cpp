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



signed main(){
cin.tie(0);
ios::sync_with_stdio(false);

	int N;
	cin >> N;
	VI A(N);
	REP(i, N)cin >> A[i];

	SORT(A);

	int ans = 0;
	VI P, F;

	P.push_back(A[N - 1]);
	F.push_back(A[0]);

	ans += A[N - 1];
	ans -= A[0];

	FOR(i, 1, N - 1) {
		if (A[i] >= 0) {
			P.push_back(A[i]);
			ans += A[i];
		}
		else {
			F.push_back(A[i]);
			ans -= A[i];
		}
	}


	cout << ans << endl;

	FOR(i, 1, N - 1) {
		if (A[i] < 0) {
			cout << A[N - 1] << " " << A[i] << endl;
			A[N - 1] -= A[i];
		}
		else {
			cout << A[0] << " " << A[i] << endl;
			A[0] -= A[i];
		}
	}

	cout << A[N - 1] << " " << A[0] << endl;


	
	return 0;
}

