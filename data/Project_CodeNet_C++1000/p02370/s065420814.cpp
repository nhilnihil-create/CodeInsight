#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<numeric>
#include<iostream>
#include<array>
#include<string>
#include<sstream>
#include<stack>
#include<queue>
#include<list>
#include<functional>
#define _USE_MATH_DEFINES

#include<math.h>
#include<map>

#define SENTINEL 1000000001

#define min(a,b) ((a)>(b)?(b):(a))
#define max(a,b) ((a)>(b)?(a):(b))

#define INF 200000000

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;

vector<int> G[10000];
vector<int> L;
bool checked[10000];

void visit(int n)
{
	if (!checked[n])
	{
		checked[n] = true;
		for (auto& m : G[n])
		{
			visit(m);
		}
		L.push_back(n);
	}
}

int main() 
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int V, E;
	scanf("%d %d", &V, &E);

	for (int i = 0; i < E; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);

		G[u].push_back(v);
	}

	for (int i = 0; i < V; i++)
	{
		visit(i);
	}

	reverse(L.begin(), L.begin() + V);
	for (int i = 0; i < V; i++)
	{
		printf("%d\n", L[i]);
	}
	return 0;
}
