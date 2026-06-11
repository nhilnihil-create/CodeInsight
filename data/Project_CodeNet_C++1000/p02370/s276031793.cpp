#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>

#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <functional>

#include <list>

using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define INF 1<<29
#define ALEN(ARR) (sizeof(ARR) / sizeof((ARR)[0]))
#define MP make_pair
#define mp make_pair
#define pb push_back
#define PB push_back
#define _DEBUG(x) cout<<#x<<": "<<x<<endl
#define _DDEBUG(x,y) cout<<#x<<": "<<x<<", "<<#y<<": "<<y<<endl
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

// topological sort p345
// ??????????????°??£?????????
// bfs 

static const int MAX = 100000;

vector<int> G[MAX];
vector<int> out;
bool V[MAX];
int N;

void dfs(int u) {
	V[u] = true;
	for(auto &v : G[u]) {
		if( !V[v] ) {
			dfs(v);
		}
	}
	out.push_back(u);
}


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout.precision(16);

	int s, t, M;
	cin >> N >> M;

	REP(i, N) {
		V[i] = false;
	}

	REP(i, M) {
		cin >> s >> t;
		G[s].push_back(t);
	}

	REP(i, N) {
		if( !V[i] ) {
			dfs(i);
		}
	}

#if DEBUG
	cout << "** RESULT **" << endl; // debug
#endif

	reverse(out.begin(), out.end());
	REP(i, N) {
		cout << out[i] << endl;
	}
	return 0;
}