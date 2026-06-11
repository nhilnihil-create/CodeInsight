#include <cstdio>
#include <iostream>
using namespace std;

struct Node{
	Node(){
		parent = -1;
		depth = 0;
		left_child = -1;
		right_sibling = -1;
	}
	int parent;
	int depth;
	int left_child;
	int right_sibling;
};

void calc_depth(Node Tree[], int root, int depth)
{
	Tree[root].depth = depth;
	
	if (Tree[root].right_sibling != -1)
	{
		calc_depth(Tree, Tree[root].right_sibling, depth);
	}
	
	if (Tree[root].left_child != -1)
	{
		calc_depth(Tree, Tree[root].left_child, depth+1);
	}
	
}

void Print_Tree(Node Tree[], int n)
{
	for (int i = 0;i < n;i++)
	{
		printf("node %d: parent = %d, depth = %d, ", i, Tree[i].parent, Tree[i].depth);
		
		if (Tree[i].parent == -1)
		{
			printf("root, ");
		}
		else if (Tree[i].left_child == -1)
		{
			printf("leaf, ");
		}
		else
		{
			printf("internal node, ");
		}
		
		int tmp = i;
		printf ("[");
		if (Tree[i].left_child != -1)
		{
			tmp = Tree[i].left_child;
			printf("%d", tmp);
			while(Tree[tmp].right_sibling != -1)
			{
				tmp = Tree[tmp].right_sibling;
				printf(", ");
				printf("%d", tmp);
			}
		}
		printf ("]\n");
	}
}

int main ()
{
	int n;
	cin >> n;
	Node *Rooted_Tree = new Node [n];
	
	int root;
	for (int i = 0;i < n;i++)
	{
		int id, k, c, L_Child;
		cin >> id >> k;
		for (int j = 0;j < k;j++)
		{
			cin >> c;
			if (j)
			{
				Rooted_Tree[L_Child].right_sibling = c;
			}
			else
			{
				Rooted_Tree[id].left_child = c;
			}
			
			L_Child = c;
			Rooted_Tree[c].parent = id;
		}
	}

	for (int i = 0;i < n;i++)
	{
		if (Rooted_Tree[i].parent == -1)
		{
			root = i;
			break;
		}
	}
	
	calc_depth(Rooted_Tree, root, 0);
	
	Print_Tree(Rooted_Tree, n);
	
	return 0;
}
