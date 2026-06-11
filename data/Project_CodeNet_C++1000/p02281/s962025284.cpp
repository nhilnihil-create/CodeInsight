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
	int height;
	int sibling;
	Type type;
	int left;
	int right;
};

OwnNode tree[100001];
bool isChild[100001];
const string typeStr[] = { "root","internal node","leaf" };

int TrackTree(int parentid,int id, int depth)
{
	/*int height = 0;
	tree[id].parent = parentid;
	tree[id].depth = depth;
	for (int i = 0; i != tree[id].children.size(); i++)
	{
		height = max(height, TrackTree(id, tree[id].children[i], depth + 1));
	}
	if (tree[id].children.size() == 2)
	{
		tree[tree[id].children[0]].sibling = tree[tree[id].children[1]].id;
		tree[tree[id].children[1]].sibling = tree[tree[id].children[0]].id;
	}
	tree[id].height = height;
	return height + 1;*/
	return 0;
}

void PreOrder(int id)
{
	printf(" %d", id);
	if (tree[id].left!=-1)
	{
		PreOrder(tree[id].left);
	}
	if (tree[id].right!=-1)
	{
		PreOrder(tree[id].right);
	}
}

void InOrder(int id)
{
	if (tree[id].left != -1)
	{
		InOrder(tree[id].left);
	}
	printf(" %d", id);
	if (tree[id].right != -1)
	{
		InOrder(tree[id].right);
	}
}

void PostOrder(int id)
{
	if (tree[id].left != -1)
	{
		PostOrder(tree[id].left);
	}
	if (tree[id].right != -1)
	{
		PostOrder(tree[id].right);
	}
	printf(" %d", id);
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int id,left,right;
		scanf("%d %d %d", &id, &left, &right);

		tree[id].id = id;
		tree[id].depth = 0;
		tree[id].sibling = -1;
		tree[id].parent = -1;
		tree[id].left = left;
		tree[id].right = right;

		if (left != -1)
		{
			isChild[left] = true;
		}
		if (right != -1)
		{
			isChild[right] = true;
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

	/*TrackTree(-1, rootID, 0);

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
		printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n", tree[i].id, tree[i].parent, tree[i].sibling,tree[i].children.size(),tree[i].depth, tree[i].height,typeStr[(int)tree[i].type].c_str());
	}*/

	printf("Preorder\n");
	PreOrder(rootID);
	printf("\nInorder\n");
	InOrder(rootID);
	printf("\nPostorder\n");
	PostOrder(rootID);
	printf("\n");

	return 0;
}
