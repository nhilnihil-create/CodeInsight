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
	vector<pair<double,double> >V(N);
	REP(i, N)cin >> V[i].first >> V[i].second;
	SORT(V);
	sort(V.begin(), V.end(), [](const auto &p1, const auto &p2) {
		return atan2l(p1.second, p1.first) < atan2l(p2.second, p2.first);
	});
	double ans = 0;

	REP(l, N) {
		int r = l;
		pair<double, double> now;
		now.first = now.second = 0;
		REP(j, N) {
			now.first += V[r].first;
			now.second += V[r].second;
			double x = now.first, y = now.second;
			ans = max(ans, pow(x*x + y * y, 0.5));
			r = (r + 1) % N;
		}
	}

	
	printf("%.12f\n", ans);

	return 0;
}

