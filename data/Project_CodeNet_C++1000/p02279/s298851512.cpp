/*
 * ALDS1_7_A.cpp
 *
 *  Created on: Apr 30, 2018
 *      Author: 13743
 */

#include<cstdio>

struct Node {
	int pa;
	int lc;
	int rs;
};

Node tree[100000];

int depth(int u) {
	int de = 0;
	while(tree[u].pa != -1) {
		de++;
		u = tree[u].pa;
	}
	return de;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		tree[i].pa = -1;
		tree[i].lc = -1;
		tree[i].rs = -1;
	}
	for(int i=0; i<n; i++) {
		int id, d;
		scanf("%d%d", &id, &d);
		for(int j=0; j<d; j++) {
			int ch0;
			int ch;
			scanf("%d", &ch);
			tree[ch].pa = id;
			if(j == 0) {
				tree[id].lc = ch;
			}
			else {
				tree[ch0].rs = ch;
			}
			ch0 = ch;
		}
	}

	for(int i=0; i<n; i++) {
		printf("node %d: ", i);
		printf("parent = %d, ", tree[i].pa);
		printf("depth = %d, ", depth(i));
		if(tree[i].pa == -1) {
			printf("root, ");
		}
		else if(tree[i].lc == -1) {
			printf("leaf, ");
		}
		else {
			printf("internal node, ");
		}
		printf("[");
		int sib = -1;
		if(tree[i].lc != -1) {
			printf("%d", tree[i].lc);
			sib =  tree[tree[i].lc].rs;
		}
		while(sib != -1) {
			printf(", %d", sib);
			sib = tree[sib].rs;
		}
		printf("]\n");
	}
}



