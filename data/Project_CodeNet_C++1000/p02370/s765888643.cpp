
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include<vector>
#include<cstring>
#include<set>
#include <cstdio>
#include<queue>
#include<map>
#define WHITE 0
#define GRAY  1
#define BLACK 2
#define endl '\n'
#define forup(i,a,n) for( int i =a; i < n; i++)
#define llforup(i,a,n) for( ll i =a; i < n; i++)
#define fordown(i,a,n) for( int i =a; i >= n; i--)
#define fornot(i,a,n) for( int i=a;!n;i++)
#define mod  (ll)(1e9+7)
#define ifempty(a)  if(!a)
using namespace std;
typedef long long ll;
inline int readnum()
{
	int p, data = 0; char ch = 0;
	while ((ch != '-') &&( ch < '0' || ch>'9') )//注意运算优先级，逻辑与大于逻辑非
		ch = getchar();//相当于正则表达式的搜索，跳过不需要的字符
	if (ch == '-')
		p = -1, ch = getchar();//不能与if平行放置，不懂为什么，可能是bug
	else p = 1;
	while (ch >= '0' && ch <= '9') data = data * 10 + ch - '0', ch = getchar();//搜索需要的字符
	return data * p;
}
inline int ReadPossitive()
{
	char ch; int data = 0;
	ch = getchar();
	while (ch == ' ' || ch == '\n')ch = getchar();
	while (ch != ' ' && ch != '\n' && ch != EOF)
	{
		data = data * 10 + ch - '0';
		ch = getchar();
	}
	return data;
}
//E-mail 374656045@qq.com
class solve {
private:
	int v, e;
	vector<int>*G;
	bool* vis;//有向图必须有vis,一次dfs||bfs能遍历一颗树，但是一个根和一棵树，但是一颗树可能有多个根2->3,1->3;
	int *order;
	int ordersize;
public://采用邻接表建图
	solve(const char kind[])
	{
		initial();
		if (kind == "bfs")
		{
			TsortBfs();
			forup(i, 0, ordersize)
				printf("%d\n", order[i]);
		}
		if (kind == "dfs")
		{
			TsortDfs();
			for(int i=ordersize-1;i>=0;i--)
				printf("%d\n", order[i]);
		}
	}
	void initial()
	{
		v = ReadPossitive(); e = ReadPossitive();
		G = new vector<int>[v];
		vis = new bool[v]();
		order = new int[v];
		ordersize = 0;
		int u, to;
		forup(i, 0, e)
		{
			u = ReadPossitive(); to = ReadPossitive();
			G[u].push_back(to);
		}
	}
	void TsortBfs()
	{
		int *indeg=new int[v]();//初始化入度为0
		forup(i,0,v)
			forup(j, 0, G[i].size())
		{
			indeg[G[i][j]]++;
		}
		forup(i, 0, v)
			if (indeg[i]==0&&!vis[i])
			{
				queue<int>temp;
				temp.push(i);
				int cur, son;
				while (!temp.empty())
				{
					cur = temp.front(); temp.pop(); vis[cur] = true; order[ordersize++] = cur;
					forup(i, 0, G[cur].size())
					{
					    son = G[cur][i];
						indeg[son]--;
						if (indeg[son] == 0 && !vis[son])
							temp.push(son);//避免多根共用的子树被重复操作,所以1->2,3->2的顺序是1,3,2。满足拓扑排序的要求：所有平级的父节点排在子节点前面。
						//先输出多根共用子树中不重合的部分，再输出重合的部分，这是跟TsortDfs不同的最大区别
					}
				}
			}
	}
	void TsortDfs()//思维相对简单一些
	{
		forup(i, 0, v)
			if(!vis[i])dfs(i);//直接递归，不手动写栈了
	}
	void dfs(int i)
	{
		vis[i] = true;
		int son;
		forup(j, 0, G[i].size())
		{
			son = G[i][j];
			if(!vis[son])
			dfs(son);
		}
		order[ordersize++] = i;//注意顺序是逆序的,并且是将多个根共用的子树根据先来后到原则进行剖分，剖分为独立子树输出（345012）
	}
};
int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0);//慎用，cin和scanf混用会导致非MSC++WA
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve solution("bfs");
#ifdef DEBUG
	fclose(stdin);//关闭文件 
	fclose(stdout);//关闭文件 
#endif
	return 0;

}


