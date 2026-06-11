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
int h,w;
char c[101][101];
int d[101][101] = {};

int dh[2] = {0,1};
int dw[2] = {1,0};

bool isin(int i,int j){
	return (0 <= i && i < h && 0 <= j && j < w);
}

int bfs(){
	rep(i,h)rep(j,w)d[i][j] = INF;
	d[0][0] = 1;
	if(c[0][0] == '.')d[0][0] = 0;
	queue<pii> q;
	q.push(MP(0,0));
	while(q.size()){
		pii p = q.front();
		q.pop();
		rep(i,2){
			int nh = p.fi + dh[i];
			int nw = p.se + dw[i];
			int next_dist;
			if(c[p.fi][p.se] == '.' && c[nh][nw] == '#')next_dist = d[p.fi][p.se]+1;
			else next_dist = d[p.fi][p.se];
			if(isin(nh,nw) && d[nh][nw] > next_dist){
				q.push(MP(nh,nw));
				d[nh][nw] = next_dist;
			}
		}
	}
	return d[h-1][w-1];
}

/*----------------------------------------------------------------*/
signed main(){

	cin >> h >> w;
	rep(i,h)rep(j,w)cin >> c[i][j];

	cout << bfs() << endl;

	return 0;
}
/*----------------------------------------------------------------*/

// g++ -std=gnu++17 code1.cpp
// sudo pip3 install --upgrade online-judge-tools
// rm -r -f test;oj dl https://code-festival-2017-qualb.contest.atcoder.jp/tasks/code_festival_2017_qualb_b
// rm -r -f test;oj dl https://agc043.contest.atcoder.jp/tasks/agc043_a
