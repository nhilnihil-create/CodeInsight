#include<iostream>
#include<vector>
#include<stack>
#define MAX 100000
#define NIL -1

// 隣接リスト
std::vector<int> G[MAX];

// 隣接する頂点に同じ色を付けて記録するデータ
int color[MAX];

// 頂点数
int n;

// 深さ探索
// 探索した頂点には隣接頂点の印としてcの色を付ける
void dfs(int r, int c)
{
	std::stack<int> S;
	S.push(r);
	color[r] = c;

	while (!S.empty())
	{
		int u = S.top();
		S.pop();
		for (int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i];
			if (color[v] == NIL)
			{
				color[v] = c;
				S.push(v);
			}
		}
	}
}

// 色を付けて隣接頂点同士に分類する
void assignColor()
{
	int id = 1;
	for (int i = 0; i < n; i++)color[i] = NIL;
	for (int u = 0; u < n; u++)
	{
		if (color[u] == NIL)dfs(u, id++);
	}
}

int main()
{
	int m;
	std::cin >> n >> m;

	int s, t;
	for (int i = 0; i < m; i++)
	{
		std::cin >> s >> t;
		G[s].push_back(t);
		G[t].push_back(s);
	}

	assignColor();

	int q;
	std::cin >> q;
	for (int i = 0; i < q; i++)
	{
		std::cin >> s >> t;
		if (color[s] == color[t])
		{
			std::cout << "yes" << std::endl;
		}
		else
		{
			std::cout << "no" << std::endl;
		}
	}

	return 0;
}

// 参考
// ALDS1_11_B_DepthFirstSearchと同じロジックで深さ探索を実装
void dfs_2(int r, int c)
{
	std::stack<int> S;
	S.push(r);
	color[r] = c;
	while (!S.empty())
	{
		int u = S.top();
		int v = -1;
		for (int i = 0; i < G[u].size(); i++)
		{
			if (color[G[u][i]] == NIL)
			{
				v = G[u][i];
			}
		}
		if (v != -1)
		{
			S.push(v);
			color[v] = c;
		}
		else
		{
			S.pop();
		}
	}
}

