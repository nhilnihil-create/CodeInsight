#include <cstdio>
const int NIL = -1;
struct node {
	int parent;
	int left;
	int right;
};

node nodes[100000];

int depth(int i) {
	int count = 0;
	while (nodes[i].parent != NIL) {
		i = nodes[i].parent;
		count++;
	}
	return count;
}

void type(int i) {
	if (nodes[i].parent == NIL) {
		printf("root");
	} else if (nodes[i].left == NIL) {
		printf("leaf");
	} else {
		printf("internal node");
	}
}

int main()
{
	int n;
	for (int i = 0; i < 100000; ++i) {
		node &p = nodes[i];
		p.parent = NIL;
		p.left = NIL;
		p.right = NIL;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int v, m;
		scanf("%d %d", &v, &m);
		node &r = nodes[v];
		int prev = v;
		for (int j = 0; j < m; ++j) {
			int c;
			scanf("%d", &c);
			node &q = nodes[c];
			q.parent = v;
			if (j == 0) {
				r.left = c;
			} else {
				nodes[prev].right = c;
			}
			prev = c;
		}
	}

	for (int i = 0; i < n; ++i) {
		printf("node %d: parent = %d, depth = %d, ",
				i, nodes[i].parent, depth(i));
		type(i);
		int c = nodes[i].left;
		printf(", [");
		if (c != NIL) {
			int j = 0;
			while(c != NIL) {
				if (j > 0) { printf(", "); }
				printf("%d", c);
				j++;
				c = nodes[c].right;
			}
		}
		printf("]");
		printf("\n");
	}

	return 0;
}