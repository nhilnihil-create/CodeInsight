#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using msi = map<string, int>;
using mii = map<int, int>;
using psi = pair<string, int>;
using pii = pair<int, int>;
using vlai = valarray<int>;
#define rep(i,n) for(int i=0;i<n;i++)
#define range(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define INF 1E9
#define EPS 1E-9
#define MOD (1E9+7)
#define PI 3.1415926535897932384626433832795

std::ostream &operator<<(std::ostream &out, const vector<int> &tgt)
{
	string s;
	for (int i = 0; i<tgt.size(); i++) {
		s += (to_string(tgt[i]) + ((i != tgt.size() - 1) ? " " : ""));
	}
	out << s;
	return out;
}
struct node {
	vi to;
	int dist = -1;
	bool visited = false;
};

vector<node> g;
int t = 0;

void bfs(int n) {
	queue<pii> q;
	q.push({n,0});
	while (!q.empty()) {
		int dis = q.front().sc;
		int node = q.front().fs;
		q.pop();
		if (g[node].visited)continue;
		//cout << node + 1 << endl;
		g[node].dist = dis;
		g[node].visited = true;
		rep(i, g[node].to.size()) {
			if (!g[g[node].to[i]].visited)q.push({ g[node].to[i],dis + 1 });
		}
	}
}

int main(){
	int n,in,inn;
	cin >> n;
	g.resize(n);
	rep(i, n) {
		cin >> in;
		cin >> in;
		rep(j, in) {
			cin >> inn;
			g[i].to.push_back(inn-1);
		}
	}
	rep(i, n) {
		if (!g[i].visited) {
			bfs(0);
		}
	}
	rep(i, n) {
		cout <<i+1<<" "<< g[i].dist <<endl;
	}
}
