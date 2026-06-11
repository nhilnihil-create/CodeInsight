#include <stdio.h>

const int N = 100000;
const int NIL = -1;

struct Node
{
	int parent, left, right;
};

Node T[N];
int d[N];

void getDepth(int u, int p)
{
	d[u] = p;
	if (T[u].left != NIL)
		getDepth(T[u].left, p + 1);
	if (T[u].right != NIL)
		getDepth(T[u].right, p);
}

void print(int u)
{
	printf("node %d: parent = %d, depth = %d, ",
			u, T[u].parent, d[u]);
	if (T[u].parent == NIL)
		printf("root, ");
	else if (T[u].left == NIL)
		printf("leaf, ");
	else
		printf("internal node, ");
	printf("[");
	/*
	if (T[u].left != NIL)
	{
		printf("%d", T[u].left);
		int c = T[T[u].left].right;
		while (c != NIL)
		{
			printf(", %d", c);
			c = T[c].right;
		}
	}
	*/
	// 更简洁的写法
	for (int i = 0, c = T[u].left; c != NIL; i++, c = T[c].right)
	{
		if (i > 0)
			printf(", ");
		printf("%d", c);
	}

	printf("]\n");
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		T[i].parent = T[i].left = T[i].right = NIL;

	for (int i = 0; i < n; i++)
	{
		int v, d, l;
		scanf("%d%d", &v, &d);
		for (int j = 0; j < d; j++)
		{
			int c;
			scanf("%d", &c);
			if (j == 0)
				T[v].left = c;
			else
				T[l].right = c;
			T[c].parent = v;
			l = c;
		}
	}
	int r;
	for (int i = 0; i < n; i++)
		if (T[i].parent == NIL)
			r = i;

	getDepth(r, 0);

	for (int i = 0; i < n; i++)
		print(i);

	return 0;
}

