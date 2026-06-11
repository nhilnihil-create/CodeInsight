#include<iostream>
#include<list>
#include<vector>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define MAX 10000

class Node;
void dfs(int N);

class Node
{
public:
	bool IsDone = false;
	vector<int> E;
};

list<int> ans;
Node nodes[MAX];

void dfs(int N)
{
	nodes[N].IsDone = true;
	for (int i = 0; i<nodes[N].E.size(); i++)
	{
		if (nodes[nodes[N].E[i]].IsDone == false)
		{
			dfs(nodes[N].E[i]);
		}
	}
	ans.push_front(N);
}

int main()
{
	int V, E;
	cin >> V >> E;
	REP(i, E)
	{
		int s, t;
		cin >> s >> t;
		nodes[s].E.push_back(t);
	}
	REP(i, V)if (nodes[i].IsDone == false)dfs(i);
	for (auto var : ans)cout << var << endl;
	return 0;
}