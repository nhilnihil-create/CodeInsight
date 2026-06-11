#include <iostream>
#include <algorithm>
using namespace std;
#define NIL -1
struct Node {
	int depth, left, right, parent;
	Node()
	{
		left = right = parent = NIL;
	}
}node[1000005];

void setDepth(int x, int d)
{
	node[x].depth = d;
	if (node[x].left != NIL)
		setDepth(node[x].left, d + 1);
	if (node[x].right != NIL)
		setDepth(node[x].right, d);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, id, k, root;
	int c[100005];
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> id >> k;
		if (k > 0)
		{
			cin >> c[0];
			node[id].left = c[0];
			node[c[0]].parent = id;
			for (int j = 1; j < k; j++)
			{
				cin >> c[j];
				node[c[j - 1]].right = c[j];
				node[c[j]].parent = id;
			}
		}
	}
	for (root = 0; root < n; ++root)
		if (node[root].parent == NIL)
			break;

	setDepth(root, 0);

	for (int i = 0; i < n; ++i)
	{
		cout << "node " << i << ": parent = " << node[i].parent << ", depth = " << node[i].depth << ", ";
		if (node[i].parent == NIL)
			cout << "root, ";
		else if (node[i].left == NIL)
			cout << "leaf, ";
		else
			cout << "internal node, ";
		cout << '[';
		if (node[i].left != NIL)
		{
			int j = node[i].left;
			cout << j;
			while (node[j].right != NIL)
			{
				j = node[j].right;
				cout << ", " << j;
			}
		}
		cout << ']' << endl;
	}

	return 0;
}