#include <cstdio>
#include <cstdlib>
#include <cstring>

struct node{
	int n_chilledren;
	int *id_chilledren;
	int id_parent;
	int depth;
	char type[15];
};

struct tree{
	int n_nodes;
	node *nodes;
};

void link(tree t, int id){
	int i, id_child;
	for(i=0;i<t.nodes[id].n_chilledren;i++){
		id_child = t.nodes[id].id_chilledren[i];
		t.nodes[id_child].id_parent = id;
		if(t.nodes[id_child].n_chilledren == 0){
			strcpy(t.nodes[id_child].type, "leaf");
		}
		else{
			strcpy(t.nodes[id_child].type, "internal node");
		}
	}
}

void printNodes(tree t){
	int i,j,n;
	n = t.n_nodes;
	for(i=0;i<n;i++){
		printf("node %d: ", i);
		printf("parent = %d, ", t.nodes[i].id_parent);
		printf("depth = %d, ", t.nodes[i].depth);
		printf("%s, ", t.nodes[i].type);
		printf("[");
		if(t.nodes[i].n_chilledren>0){
			for(j=0;j<t.nodes[i].n_chilledren-1;j++){
				printf("%d, ", t.nodes[i].id_chilledren[j]);
			}
			printf("%d",t.nodes[i].id_chilledren[j]);
		}
		printf("]\n");
		
	}
}

void setDepth(tree t, int id, int d){
	int i;
	t.nodes[id].depth = d;
	for(i=0;i<t.nodes[id].n_chilledren;i++){
		setDepth(t, t.nodes[id].id_chilledren[i], d+1);
	}
}

int main(void){
	tree t;
	int i,j, id, n;
	scanf("%d", &t.n_nodes);
	t.nodes = new node[t.n_nodes];
	
	for(i=0;i<t.n_nodes;i++){
		t.nodes[id].id_parent = -1;
		scanf("%d %d", &id, &n);
		t.nodes[id].n_chilledren = n;
		if(n>=0){
			t.nodes[id].id_chilledren = new int[n];
			for(j=0; j<n; j++){
				scanf("%d", &t.nodes[id].id_chilledren[j]);
			}
		}
	}
	for (i=0;i<t.n_nodes;i++){
		if(t.nodes[i].n_chilledren >0) link(t, i);
	}
	for (i=0;i<t.n_nodes;i++){
		if(t.nodes[i].id_parent == -1){
			strcpy(t.nodes[i].type, "root");
			id = i;
			break;
		}
	}
	setDepth(t, id, 0);
	printNodes(t);
	delete []t.nodes;

	return 0;
}