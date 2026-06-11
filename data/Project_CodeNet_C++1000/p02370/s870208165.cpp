#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <functional>
#include <numeric>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iomanip>
#include <map>
#include <set>
#include <cstdlib>
#include <bitset>
using namespace std;
#define INT_MAX 2147483647
#define INT_MIN (-2147483647 - 1)
#define INF 100000000
#define _INF -100000000
#define INFLL (long long)1e14
#define _INFLL (long long)-1e14
#define Loop(i, n) for(int i = 0; i < (int)n; i++)
#define Loop1(i, n) for(int i = 1; i <= (int)n; i++)
#define Loopr(i, n) for(int i = (int)n - 1; i >= 0; i--)
#define Loopr1(i, n) for(int i = (int)n; i >= 1; i--)
#define bitmanip(m,val) static_cast<bitset<(int)m>>(val)
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef pair<int, int> P;


class Topological_Sort {
private:
	int n;
	vvi G;
	vi visited;
public:
	deque<int> ret;
	Topological_Sort(vvi A) {
		G = A;
		n = G.size();
		visited.resize(n);
		fill(visited.begin(), visited.end(), 0);
		mainf();
	}
	void mainf() {
		Loop(i, n) {
			if (visited[i] == 0) dfs(i);
		}
	}
	bool dfs(int a) {
		if (visited[a] == 1) {
			ret.clear();
			return -1;
		}
		else if (visited[a] == 0) {
			visited[a] = 1;
			Loop(j, G[a].size()) {
				if (dfs(G[a][j])) return -1;
			}
			visited[a] = 2;
			ret.push_front(a);
		}
		return 0;
	}
};

int main() {
	int n, m; cin >> n >> m;
	vvi A(n);
	Loop(i, m) {
		int s, t; cin >> s >> t;
		A[s].push_back(t);
	}
	Topological_Sort ts(A);
	Loop(i, ts.ret.size()) {
		cout << ts.ret[i] << endl;
	}
	return 0;
}