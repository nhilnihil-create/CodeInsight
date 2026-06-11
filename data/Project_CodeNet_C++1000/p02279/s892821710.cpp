#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <utility>
#include <numeric>

using namespace std;

#define INF 1 << 30
#define MOD 1000000000 + 7

#define NIL -1

struct Node
{
	int p, l, r;

	Node()
	{

	}

	Node(int p, int l, int r)
	{
		this->p = p;
		this->l = l;
		this->r = r;
	}
};

vector<Node> t;
vector<int> depth;

void rec(int u, int p)
{
	depth.at(u) = p;
	if (t.at(u).r != NIL)
	{
		rec(t.at(u).r, p);
	}
	if (t.at(u).l != NIL)
	{
		rec(t.at(u).l, p + 1);
	}
}

int main()
{
	int n;
	cin >> n;

	depth.resize(n);

	for (int i = 0; i < n; i++)
	{
		t.push_back(Node(-1, -1, -1));
	}

	int l;
	for (int i = 0; i < n; i++)
	{
		int v, d;
		cin >> v >> d;
		for (int j = 0; j < d; j++)
		{
			int c;
			cin >> c;

			if (j == 0)
			{
				t.at(v).l = c;
			}
			else
			{
				t.at(l).r = c;
			}
			l = c;
			t.at(c).p = v;
		}
	}

	int r;
	for (int i = 0; i < n; i++)
	{
		if (t.at(i).p == NIL)
		{
			r = i;
		}
	}

	rec(r, 0);

	for (int i = 0; i < n; i++)
	{
		cout << "node " << i << ": ";
		cout << "parent = " << t.at(i).p << ", ";
		cout << "depth = " << depth.at(i) << ", ";

		if (t.at(i).p == NIL)
		{
			cout << "root, ";
		}
		else if (t.at(i).l == NIL)
		{
			cout << "leaf, ";
		}
		else
		{
			cout << "internal node, ";
		}

		cout << "[";

		for (int j = 0, c = t.at(i).l; c != NIL; j++, c = t.at(c).r)
		{
			cout << (j > 0 ? ", " : "") << c;
		}

		cout << "]" << endl;
	}
}
