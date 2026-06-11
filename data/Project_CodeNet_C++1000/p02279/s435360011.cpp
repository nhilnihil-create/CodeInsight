#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef struct
{
	int id;
	int parent;
	int depth;
	int numOfChild;
	string type;
	vector<int> children;

} Node;
int getDepth(Node nodes[],int n)
{
	int depth = 0;
	Node now = nodes[n];
	while (now.parent != -1)
	{
		now = nodes[now.parent];
		depth++;
	}

	return depth;
}

void setDepth(Node nodes[],int n,int d)
{
	nodes[n].depth = d;
	for (int i = 0; i < nodes[n].numOfChild; i++)
	{
		setDepth(nodes, nodes[n].children.at(i), d + 1);
	}
}
int main()
{
	static Node node[100000 + 1];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		node[i].depth = 0;
		node[i].parent = -1;
	}
	for (int i = 0; i < n; i++)
	{
		int id, k;
		cin >> id >> k;
		node[id].id = id;
		node[id].numOfChild = k;
		for (int j = 0; j < k; j++)
		{
			int c;
			cin >> c;
			node[id].children.push_back(c);
			node[c].parent = id;
			node[c].depth = node[id].depth + 1;
		}
	}
	int root;
	for (int i = 0; i < n; i++)
	{
		if (node[i].parent == -1)
		{
			root = i;
			node[i].type = "root";
		}
		else if (node[i].numOfChild > 0)
		{
			node[i].type = "internal node";
		}
		else
		{
			node[i].type = "leaf";
		}
	}
	setDepth(node, root, 0);
	for (int i = 0; i < n; i++)
	{
		cout << "node " << i << ": parent = " << node[i].parent << ", depth = " << node[i].depth<< ", " << node[i].type << ", [";
		for (int j = 0; j < node[i].numOfChild; j++)
		{
			if (j == 0)
			{
				cout << node[i].children[j];
			}
			else
			{
				cout << ", " << node[i].children[j];
			}
		}

		cout << "]" << endl;
	}
}