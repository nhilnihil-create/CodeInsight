#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>

#define PI 3.14159265359

#define INF 99999999;

#define rep(i, n) for(int i=0; i<n; i++)
#define REP(n) rep(i, n)

typedef long long ll;

using namespace std;



/*
class LightSwitchingPuzzle
{
public:
	int minFlips(string s)
	{

	}
}
*/


int rank[100000];
int par[10000];

void init(int n)
{
	REP(n)
	{
		rank[i] = 0;
		par[i] = i;
	}
}

int find(int x)
{
	if (par[x] == x) return x;
	else return par[x] = find(par[x]);
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y) return;
	
	if (rank[x] < rank[y])
	{
		par[x] = y;
	} else {
		par[y] = x;
		if (rank[x] == rank[y]) rank[x]++;
	}
}

bool same(int x, int y)
{
	return find(x) == find(y);
}

struct edge
{
	int u, v, cost;
};

bool comp(const edge& e1, const edge& e2)
{
	return e1.cost < e2.cost;
}

edge es[100000];

int main()
{
	int V, E;
	
	cin >> V >> E;
	REP(E)
	{
		cin >> es[i].u >> es[i].v >> es[i].cost;
	}
	
	sort(es, es + E, comp);
	init(V);
	int res = 0;
	for (int i=0; i<E; i++)
	{
		edge e = es[i];
		if (!same(e.u, e.v))
		{
			unite(e.u, e.v);
			res += e.cost;
		}
	}
	
	cout << res << endl;
	
	return 0;
}