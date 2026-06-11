#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define repi(i,x) for(auto i=(x).begin(),i##_fin=(x).end();i!=i##_fin;i++)
#define all(x) (x).begin(), (x).end()
#define input(array) repi(array##_itr, array) { cin >> *(array##_itr); }
#define F first
#define S second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
string solve(bool a) { return ((a) ? "Yes" : "No"); }
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef pair<int , int> Pi;
typedef vector<Pi> VPi;
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long , long long> P;
typedef vector<P> VP;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
const long long INFLL = 1LL<<60;
const int INF = 1<<30;
const double PI=acos(-1);
int main() {
	int n, x, y;
	// int ans=0;
	cin >> n >> x >> y;
	vector<vector<int>> path(n);
	rep(i, n) {
		if (i != 0) {
			path[i].push_back(i - 1);
	
		}
		if (i != n - 1) {
			path[i].push_back(i + 1);
		}
	}
	x--;
	y--;
	path[x].push_back(y);
	path[y].push_back(x);
	vector<int> ans(n ,0);
	vector<int> dis(n, INF);
	queue<int> q;
	int at;
	rep(i, n) {
		q.push(i);
		rep(j, n) { dis[j] = INF; }
		dis[i] = 0;
		while (!q.empty()) {
			at = q.front();
			q.pop();
			repi(itr, path[at]) {
				if (chmin(dis[*itr], dis[at] + 1)) {
					q.push(*itr);
				}
			}
		}
	//	rep(j, n) { clog << dis[j] << " "; }
	//	clog << endl;
		for (int j = i + 1; j < n;j++) {
			if (dis[j] == INF) continue;
			ans[dis[j]]++;
		}
	}
	for (int i = 1; i < n; i++) {
		cout << ans[i] << endl;
	}
}