#include <iostream>
#include <vector>

using namespace std;

struct Node {
	Node() { parent = -1; depth = 0; }

	int parent;
	int depth;
	vector<int> children;
};

vector<Node> node(100000);

void set_depth(int id)
{
	if (node[id].children.empty())
		return;

	for (int i = 0; i < node[id].children.size(); ++i)
	{
		node[node[id].children[i]].depth = node[id].depth + 1;
		set_depth(node[id].children[i]);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int id, k;
		cin >> id >> k;

		while (k--)
		{
			int c;
			cin >> c;
			node[id].children.push_back(c);
			node[c].parent = id;
		}
	}

	for (int i = 0; i < n; ++i)
		if (node[i].parent == -1)
		{
			set_depth(i);
			break;
		}

	for (int i = 0; i < n; ++i)
	{
		cout << "node " << i << ": "
			<< "parent = " << node[i].parent
			<< ", depth = " << node[i].depth
			<< (node[i].parent == -1 ?
				", root" : node[i].children.empty() ? ", leaf" : ", internal node")
			<< ", [";
		
		if (!node[i].children.empty())
		{
			cout << node[i].children[0];
			for (int j = 1; j < node[i].children.size(); ++j)
				cout << ", " << node[i].children[j];
		}
		cout << "]" << endl;
	}

	return 0;
}