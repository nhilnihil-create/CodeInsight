#define scanf_s scanf
#include <string>
#include <stdio.h>
#include <math.h>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 25
//#define MAX_ 1000

int cou = 0;

struct binarytree
{
	int id;
	binarytree *pp;
	binarytree *brather;
	binarytree *pchleft, *pchright;
};
void de_hi_1(int N, binarytree *p) {
	if (N >= 0) {
		if (p->id != -1) {
			printf(" %d", p->id);
			de_hi_1(N - 1, p->pchleft);
			de_hi_1(N - 1, p->pchright);
		}
	}
}
void de_hi_2(int N, binarytree *p) {
	if (N >= 0) {
		if (p->id != -1) {
			de_hi_2(N - 1, p->pchleft);
			printf(" %d", p->id);
			de_hi_2(N - 1, p->pchright);
		}
	}
}
void de_hi_3(int N, binarytree *p) {
	if (N >= 0) {
		if (p->id != -1) {
			de_hi_3(N - 1, p->pchleft);
			de_hi_3(N - 1, p->pchright);
			printf(" %d", p->id);
		}
	}
}
int main(void)
{
	int n, xid, xl, xr;
	binarytree node[MAX], first, nvalue;
	first.id = -1; nvalue.id = -1; nvalue.brather = &nvalue;
	bool node_b[MAX + 1] = { false };
	scanf_s("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf_s("%d %d %d", &xid, &xl, &xr);
		node[xid].id = xid;
		if (xl == -1) node[xid].pchleft = &nvalue;
		else { node[xid].pchleft = &node[xl]; }
		if (xr == -1) node[xid].pchright = &nvalue;
		else { node[xid].pchright = &node[xr]; }

		if (node_b[xid] == false) { node[xid].pp = &first; node[xid].brather = &nvalue; }

		node[xl].pp = &node[xid]; node[xr].pp = &node[xid];
		node_b[xl] = true; node_b[xr] = true;

		if (xl != -1 && xr != -1) { node[xl].brather = &node[xr]; node[xr].brather = &node[xl]; }
		else {
			if (xl != -1 && xr == -1) { node[xl].brather = &nvalue; }
			if (xl == -1 && xr != -1) { node[xr].brather = &nvalue; }
		}
	}
	for (int i = 0; i < n; ++i) {
		if (node_b[i] == false) {
			printf("Preorder\n");
			de_hi_1(n - 1, &node[i]);
			printf("\nInorder\n");
			de_hi_2(n - 1, &node[i]);
			printf("\nPostorder\n");
			de_hi_3(n - 1, &node[i]);
			printf("\n");
			break;
		}
	}
}