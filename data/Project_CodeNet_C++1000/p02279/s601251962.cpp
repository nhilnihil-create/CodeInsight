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

#define MAX 100000
//#define MAX_ 1000

int cou = 0;
struct tree
{
	int id;
	tree *pp;
	tree *next;
	tree *pchbegin, *pchend;
};
int main(void)
{
	int n, xid, xk, xdeep = 0, xc1, xc2;
	int depth, cou = 0,parent;
	tree node[MAX], first;
	first.id = -1;
	bool node_b[MAX] = { false };
	scanf_s("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf_s("%d %d", &xid, &xk);
		node[xid].id = xid;
		if (node_b[xid] == false) { node[xid].pp = &first; }
		node[xid].pchbegin = node[xid].pchend;
		for (int j = 0; j < xk; ++j) {
			scanf_s("%d", &xc1);
			node[xc1].pp = &node[xid];
			node_b[xc1] = true;
			if (j == 0) {
				node[xid].pchbegin = &node[xc1];
				node[xc1].next = node[xid].pchend;
			}
			else {
				node[xc2].next = &node[xc1];
				node[xc1].next = node[xid].pchend;
			}
			xc2 = xc1;
		}
	}
	for (int i = 0; i < n; ++i) {
		depth = 0;
		for (tree *p = node[i].pp; p != &first; p = p->pp) { ++depth; }
		printf("node %d: parent = %d, depth = %d, ", node[i].id, node[i].pp->id, depth);
		if (node[i].pchbegin == node[i].pchend && node[i].pp->id != -1) { printf("leaf, ["); }
		else {
			if (node[i].pp->id == -1) { printf("root, ["); }
			else { printf("internal node, ["); }
			for (tree *j = node[i].pchbegin; j != node[i].pchend; j = j->next) {
				if (j == node[i].pchbegin) { printf("%d", j->id); }
				else printf(", %d", j->id);
			}
		}
		printf("]\n");
	}
}