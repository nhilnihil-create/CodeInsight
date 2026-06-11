#include <bits/stdc++.h>
using namespace std;

template<typename T>
T gcd(T a, T b)
{
	return b ? gcd(b, a%b) : a;
}

template<typename T>
T lcm(T a, T b)
{
	return a / gcd(a, b) * b;
}

//(a^e)%mod
template<typename T>
T power(T a, T e, T mod)
{
	if(e == 0)
	{
		return 1;
	}
	if(e % 2 != 0)
	{
		//a^e=a^(e-1)*a
		return (power(a, e - 1, mod) * a) % mod;
	}
	T res = power(a, e / 2, mod);
	//a^e=a^(e/2)*a^(e/2)
	return (res * res) % mod;
}

template<typename T>
class Tree
{
private:
public:
	T data;
	Tree* parent = NULL;
	std::vector<Tree*> children;
	void setData(T x)
	{
		data = x;
	}
	void setParent(Tree* t)
	{
		parent = t;
	}
	void addChild(Tree* t)
	{
		children.push_back(t);
	}
	Tree(){}
	~Tree(){}
};

template<typename T>
class Graph
{
public:
	T index;
	vector<T> edge;
	void setEdge(T t)
	{
		edge.push_back(t);
	}
	Graph(){}
	~Graph(){}
};

Graph<int> G[100001];
int visited[100001];
void rec(int a, int b)
{
	if(visited[a] != 0)
	{
		return;
	}
	visited[a] = b;
	for (auto it : G[a].edge)
	{
		rec(it, b);
	}
	return;
}

int main()
{
	using namespace std;
	int n, m;
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		G[a].setEdge(b);
		G[b].setEdge(a);
	}
	for (int i = 1; i <= n; ++i)
	{
		rec(i, i);
	}
	int q;
	cin >> q;
	for (int i = 1; i <= q; ++i)
	{
		cin >> a >> b;
		cout << (visited[a] == visited[b] ? "yes" : "no") << endl;
	}

	return 0;
}

