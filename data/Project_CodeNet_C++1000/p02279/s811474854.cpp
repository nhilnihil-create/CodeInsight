#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<numeric>
#include<iostream>
#include<array>
#include<string>
#include<sstream>
#include<stack>
#include<queue>
#include<list>
#define _USE_MATH_DEFINES

#include<math.h>
#include<map>

#define SENTINEL 1000000001

#define min(a,b) (a)>(b)?(b):(a)
#define max(a,b) (a)>(b)?(a):(b)

using namespace std;

enum struct Type
{
	ROOT,
	INTERNAL,
	LEAF
};

struct OwnNode
{
	int id;
	int parent;
	int depth;
	Type type;
	vector<int> children;
};

OwnNode tree[100001];
bool isChild[100001];
const string typeStr[] = { "root","internal node","leaf" };

void TrackTree(int parentid,int id, int depth)
{
	tree[id].parent = parentid;
	tree[id].depth = depth;
	for (int i = 0; i != tree[id].children.size(); i++)
	{
		TrackTree(id,tree[id].children[i], depth + 1);
	}
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int id, cn;
		scanf("%d %d", &id, &cn);

		tree[id].id = id;
		tree[id].depth = 0;
		tree[id].parent = -1;

		for (int j = 0; j < cn; j++)
		{
			int cid;
			scanf("%d", &cid);
			tree[id].children.push_back(cid);
			isChild[cid] = true;
		}
	}

	int rootID = -1;
	for (int i = 0; i < n; i++)
	{
		if (!isChild[i])
		{
			rootID = i;
			break;
		}
	}

	TrackTree(-1,rootID, 0);

	for (int i = 0; i < n; i++)
	{
		if (tree[i].parent == -1)
		{
			tree[i].type = Type::ROOT;
		}
		else if (tree[i].children.size() == 0)
		{
			tree[i].type = Type::LEAF;
		}
		else
		{
			tree[i].type = Type::INTERNAL;
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("node %d: parent = %d, depth = %d, %s, ", tree[i].id, tree[i].parent, tree[i].depth, typeStr[(int)tree[i].type].c_str());
		printf("[");
		if (tree[i].children.size() != 0)
		{
			printf("%d", tree[i].children[0]);
			for (int j = 1; j != tree[i].children.size(); j++)
			{
				printf(", %d", tree[i].children[j]);
			}
		}
		printf("]\n");
	}

	return 0;
}
