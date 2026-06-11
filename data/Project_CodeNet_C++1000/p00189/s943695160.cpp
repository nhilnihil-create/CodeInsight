#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>

#define rep(i,n)	for(int i = 0;i < n;i++)
#define rep2(i,n)	for(int i = 1;i <= n;i++)
#define each(i,x)	for(auto & i : x)

using namespace std;

struct edge
{
	edge(int _s,int _t,int _cost)
	{
		s = _s;t = _t;cost = _cost;
	}
	int s;
	int t;
	int cost;
};

int main()
{
	int n;
	cin >> n;
	while(n)
	{
		vector<edge> ary;
		int mt = 0;
		rep(i,n)
		{
			int a,b,d;
			cin >> a >> b >> d;
			ary.push_back(edge(a,b,d));
			if(mt < a)
			{
				mt = a;
			}
			if(mt < b)
			{
				mt = b;
			}
		}
		mt++;
		vector<vector<int>> cost(mt,vector<int>(mt,1000000));
		rep(i,mt)
		{
			cost[i][i] = 0;
		}
		rep(i,ary.size())
		{
			int a = ary[i].s;
			int b = ary[i].t;
			int d = ary[i].cost;
			rep(j,mt)
			{
				rep(k,mt)
				{
					if(cost[j][k] > cost[j][a] + cost[b][k] + d)
					{
						cost[j][k] = cost[j][a] + cost[b][k] + d;
					}
					if(cost[j][k] > cost[j][b] + cost[a][k] + d)
					{
						cost[j][k] = cost[j][b] + cost[a][k] + d;
					}
				}
			}
		}
		int smin = 1000000;
		int imin = 0;
		rep(i,mt)
		{
			int s = 0;
			rep(j,mt)
			{
				s += cost[i][j];
			}
			if(smin > s)
			{
				smin = s;
				imin = i;
			}
		}
		cout << imin << ' ' << smin << endl;
		cin >> n;
	}
	return 0;
}