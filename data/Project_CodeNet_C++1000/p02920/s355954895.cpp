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
	VI S(1LL << N);
	vector<bool>F(1LL << N, false);
	REP(i, 1LL << N)cin >> S[i];
	rSORT(S);

	PQ Q,tmp;
	Q.push(S[0]);
	F[0] = true;
	
	int cnt = 0;
	while (cnt < N) {
		tmp = Q;
		int i = 0;
		while (!tmp.empty() && i<S.size()) {
			if (tmp.top() > S[i] && !F[i]) {
				Q.push(S[i]);
				F[i] = true;
				tmp.pop();
			}
			i++;
		}
		cnt++;
	}
	REP(i, S.size()) {
		if (!F[i]) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;


	return 0;

}

