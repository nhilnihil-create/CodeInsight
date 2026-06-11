#include<iostream>
#define MAX 100000
#define NIL -1

struct Node
{
	int p, left, right;
};

Node T[MAX];
int  D[MAX];

// 節点uの子をカンマ区切りで出力(2, 3, 0)
void printChildren(int u)
{
	int c = T[u].left;
	int isf = 0;
	while (c != NIL)
	{
		if (isf++ > 0) std::cout << ", ";
		std::cout << c;
		c = T[c].right;
	}
}

void print(int u)
{
	std::cout << "node " << u << ": ";
	std::cout << "parent = " << T[u].p << ", ";
	std::cout << "depth = " << D[u] << ", ";

	if (T[u].p == NIL)std::cout << "root, ";
	else if (T[u].left == NIL)std::cout << "leaf, ";
	else std::cout << "internal node, ";

	std::cout << "[";
	printChildren(u);
	std::cout << "]" << std::endl;
}

void setDepth(int u, int d)
{
	D[u] = d;
	if (T[u].left  != NIL) setDepth(T[u].left, d + 1);
	if (T[u].right != NIL) setDepth(T[u].right, d);
}

int main()
{
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		T[i].p = NIL;
		T[i].left = NIL;
		T[i].right = NIL;
	}

	int p, k, c, l;
	for (int i = 0; i < n; i++)
	{
		std::cin >> p >> k;
		for (int j = 0; j < k; j++)
		{
			std::cin >> c;
			if (j == 0)
			{
				T[p].left = c;
			}
			else
			{
				T[l].right = c;
			}
			T[c].p = p;
			l = c;
		}
	}

	int root;
	for (int i = 0; i < n; i++)
	{
		if (T[i].p == NIL)root = i;
	}
	setDepth(root, 0);

	for (int i = 0; i < n; i++)
	{
		print(i);
	}
}
