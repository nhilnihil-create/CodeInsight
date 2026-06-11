#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define int ll
typedef pair<int,int> pii;
#define fi first
#define se second
#define Sort(a) sort(a.begin(),a.end())
#define rep(i,n) for(int i = 0;i < (n) ; i++) 
#define REP(i,n) for(int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define INF LLONG_MAX/4
#define INTINF INT_MAX/2
#define all(x) (x).begin(),(x).end()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define debug_vec(v) cerr<<#v<<":";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
template<class T> inline bool chmax(T &a, T b){if(a < b){a = b;return true;}return false;}
template<class T> inline bool chmin(T &a, T b){if(a > b){a = b;return true;}return false;}
/*----------------------------------------------------------------*/
// const int MOD = 998244353;
const int MOD = 1000000007;


/*----------------------------------------------------------------*/
signed main(){


	int x,y,a,b,c;
	cin >> x >> y >> a >> b >> c;
	vll p(a),q(b),r(c);
	rep(i,a)cin >> p[i];
	rep(i,b)cin >> q[i];
	rep(i,c)cin >> r[i];

	sort(all(p),greater<int>());
	sort(all(q),greater<int>());
	sort(all(r),greater<int>());
	priority_queue<int> p2,q2,r2;
	rep(i,x)p2.push(p[i]);
	rep(i,y)q2.push(q[i]);
	rep(i,c)r2.push(r[i]);
	p2.push(-INF);
	q2.push(-INF);
	r2.push(-INF);


	int ans = 0;
	rep(i,x+y){
		int pf = p2.top();
		int qf = q2.top();
		int rf = r2.top();
		if(pf >= qf && pf >= rf){
			ans += pf;
			p2.pop();
		}else if(qf >= pf && qf >= rf){
			ans += qf;
			q2.pop();
		}else{
			ans += rf;
			r2.pop();
		}
	}
	cout << ans << endl;



	

	
	return 0;
}
/*----------------------------------------------------------------*/

// g++ -std=gnu++17 code1.cpp
// sudo pip3 install --upgrade online-judge-tools
// rm -r -f test;oj dl https://code-festival-2017-qualb.contest.atcoder.jp/tasks/code_festival_2017_qualb_b
// rm -r -f test;oj dl https://abc160.contest.atcoder.jp/tasks/abc160_e