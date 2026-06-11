#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

enum KIND {
    ROOT,
    NODE,
    LEAF,
};

struct Node {
    int id;
    enum KIND kind;
    int parent;
    vector<Node*> children;
    int depth;
};

#define MAX_N (100010)
int n;

Node T[MAX_N];

int main()
{
    int root_id;
    scanf("%d", &n);
    
    for ( int i = 0; i < n; i++ ) {
	T[i].id = i;
	T[i].parent = -1;
	T[i].kind = LEAF;
    }


    for ( int i = 0; i < n; i++ ) {
	int id, k;
	scanf("%d %d", &id, &k);
	for ( int j = 0; j < k; j++ ) {
	    int c;

	    scanf("%d", &c);
	    T[c].parent = id;	// ???????¨????

	    T[id].children.push_back( &T[c] );
	}
    }

    for ( int i = 0; i < n; i++ ) {
	if ( T[i].parent == -1 ) {
	    T[i].kind = ROOT;
	    root_id = i;
	}
	else if ( T[i].children.size() > 0 ) {
	    T[i].kind = NODE;
	}
    }

    queue<Node> Q;
    
    Q.push( T[root_id] );
    T[root_id].depth = 0;
    while ( !Q.empty() ) {
	Node nod = Q.front(); Q.pop();
	int depth = nod.depth;
	for ( int i = 0; i < nod.children.size(); i++ ) {
	    Node *p_child = nod.children[i];
	    p_child->depth = depth + 1;
	    Q.push( *p_child );
	}
    }

    for ( int i = 0; i < n; i++ ) { 
	Node nod = T[i];
	printf("node %d: parent = %d, depth = %d, ", i, nod.parent, nod.depth);
	if ( nod.kind == ROOT )	printf("root, ");
	else if ( nod.kind == NODE ) printf("internal node, ");
	else printf("leaf, ");
	
	printf("[");
	for ( int j = 0; j < nod.children.size(); j++ ) {
	    printf("%d", (nod.children[j])->id);
	    if ( j != nod.children.size() - 1 ) printf(", ");
	}
	printf("]\n");
    }

    return 0;
}