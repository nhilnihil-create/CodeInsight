#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>

#define rep(i, a) REP(i, 0, a)
#define REP(i, a, b) for(int i = a; i < b; ++i)

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> P;
typedef std::pair<P, int> PP;
struct edge{ int to, time, cost; };
const double esp = 1e-9;
const int infi = (int)1e+9 + 10;
const ll infll = (ll)1e+17 + 10;

int n, m;
std::vector<int> g[100001];
std::vector<int> l;
int used[100001];
bool isClose = false;

//??????????????????
void topologicalSort(int n){
	if (used[n] == 1){
		isClose = true;
		return;
	}
	else if (!used[n]){
		used[n] = 1;
		rep(i, g[n].size())topologicalSort(g[n][i]);
		l.push_back(n);
		used[n] = 2;
	}
}

int main(){
	std::cin >> n >> m;
	rep(i, m){
		int a, b;
		std::cin >> a >> b;
		g[a].push_back(b);
	}

	rep(i, n)if (!used[i])topologicalSort(i);
	std::reverse(l.begin(), l.end());
	rep(i, l.size())std::cout << l[i] << std::endl;;
	return 0;
}