#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;
static const int INF = 999999999;
typedef pair<int, int> P;
struct SEdge
{
	int To;
	int Cost;
};
vector<int> d;
vector<SEdge> G[10];

void Dijkstra(int s)
{
	fill(d.begin(), d.end(), INF);
	d[s] = 0;
	priority_queue<P, vector<P>, greater<P> > PQue;
	PQue.push(P(0, s));
	while(!PQue.empty())
	{
		P p = PQue.top();
		PQue.pop();
		if(d[p.second] < p.first)
		{
			continue;
		}
		int v = p.second;
		for(int i = 0; i < G[v].size(); ++i)
		{
			SEdge e = G[v][i];
			if(d[e.To] > d[v] + e.Cost)
			{
				d[e.To] = d[v] + e.Cost;
				PQue.push(P(d[e.To], e.To));
			}
		}
	}
}

void solve()
{
	int E;
	while(cin >> E, E)
	{
		int V = 0;
		for(int i = 0; i < 10; ++i)
		{
			G[i].clear();
		}
		for(int i = 0; i < E; ++i)
		{
			int From, To, Cost;
			cin >> From >> To >> Cost;
			V = max(V, max(From, To));
			SEdge e1, e2;
			e1.To = To;
			e2.To = From;
			e1.Cost = e2.Cost = Cost;
			G[From].push_back(e1);
			G[To].push_back(e2);
		}
		++V;
		d.clear();
		d.resize(V);
		unsigned long long int Min = INF;
		int pos = 0;
		for(int i = 0; i < V; ++i)
		{
			Dijkstra(i);
			unsigned long long int sum = 0;
			for(int j = 0; j < V; ++j)
			{
				sum += d[j];
			}
			if(Min > sum)
			{
				Min = sum;
				pos = i;
			}
		}
		cout << pos << " " << Min << endl;
	}
}

int main()
{
	solve();
	return(0);
}