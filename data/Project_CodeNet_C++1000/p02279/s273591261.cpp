#include <cstdio>
using namespace std;

#define MAX 100000

struct Node
{
	int parent; //??????????????????(???????????°-1)
	int left;   //??????????????????????????????
	int right;  //?????????????????????????????????
public:
	Node() { parent = left = right = -1; }
};

Node T[MAX];
int D[MAX]; //??????????????±???

void setDepth(int u, int p)
{
	D[u] = p;
	
	if (T[u].right != -1)
		setDepth(T[u].right, p);

	if (T[u].left != -1)
		setDepth(T[u].left, p + 1);
}

void show(int u)
{
	printf("node %d: ", u);
	printf("parent = %d, ", T[u].parent);
	printf("depth = %d, ", D[u]);

	if (T[u].parent == -1) printf("root");
	else if (T[u].left == -1) printf("leaf");
	else printf("internal node");
	
	printf(", [");
	int c = T[u].left;
	int flg = 0;
	while (c != -1) {
		if (flg) printf(", ");
		printf("%d", c);
		c = T[c].right;
		flg = 1;
	}
	printf("]\n");
}

int main()
{
	int n;
	scanf("%d", &n);

	int id, k, c, l;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &id, &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &c);
			if (j == 0) T[id].left = c;
			else T[l].right = c;
			l = c;
			T[c].parent = id;
		}
	}
	int r;
	for (int i = 0; i < n; i++) {
		if (T[i].parent == -1) {
			r = i;
			break;
		}
	}
	setDepth(r, 0);

	for (int i = 0; i < n; i++)
		show(i);
	return 0;		
}