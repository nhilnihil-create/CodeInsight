#include <stdio.h>
#include <vector>
#include <string>
using namespace std;


typedef struct {
    int id;			// ????????????
    int parent;			// ??????????????????
    int depth;			// ??±???
    string type;		// ??????????¨????
    vector<int> l;			// ???????????????
} Node;


void calcDepth( int id, int depth );

#define MAX_N (100010)
Node node[MAX_N];
int n;
int root_id;

int main()
{
    scanf("%d", &n);

    // ?????????
    for ( int i = 0; i < n; i++ ) {
	node[i].parent = -1;
	node[i].depth  = -1;
	node[i].type   = "internal node";
    }
    
    for ( int i = 0; i < n; i++ ) {
	int k;
	int id;
	scanf("%d %d", &id, &k);
	node[id].id = id;
	if ( k == 0 ) {
	    node[id].type = "leaf";
	}
	else {
	    for ( int j = 0; j < k; j++ ) {
		int child;
		scanf("%d", &child);
		node[id].l.push_back( child );
		node[child].parent = id;
	    }
	}
    }

    // ??????????????????
    for ( int i = 0; i < n; i++ ) {
	if ( node[i].parent == -1 ) {
	    root_id = i;
	    node[i].type = "root";
	    break;
	}
    }

    calcDepth( root_id, 0 );

    for ( int i = 0; i < n; i++ ) {
	printf("node %d: parent = %d, depth = %d, %s, ", node[i].id, node[i].parent, node[i].depth, node[i].type.c_str() );
	printf("[");
	for ( int j = 0; j < node[i].l.size(); j++ ) {
	    printf("%d", node[i].l[j]);
	    if ( j < node[i].l.size() - 1 ) {
		printf(", ");
	    }
	}
	printf("]\n");
    }
    
    return 0;
}


void calcDepth( int id, int depth )
{
    node[id].depth = depth;
    if ( node[id].l.size() ) {
	for ( int i = 0; i < node[id].l.size(); i++ ) {
	    calcDepth( node[id].l[i], depth + 1 );
	}
    }
    
    return;
}