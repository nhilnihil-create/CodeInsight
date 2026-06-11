#include <stdio.h>
#define MAX_N (30)
#define NIL (-1)


typedef struct {
    int parent;
    int left;
    int right;
} Node;


void Preorder(int id);
void Inorder(int id);
void Postorder(int id);

Node node[MAX_N];
int n;
int root_id;

int main()
{
    scanf("%d", &n);
    for ( int i = 0; i < n; i++ ) {
	node[i].parent = NIL;
    }

    for ( int i = 0; i < n; i++ ) {
	int id, left, right;
	scanf("%d %d %d", &id, &left, &right);
	node[id].left = left;
	node[id].right = right;
	if ( left != NIL ) node[left].parent = id;
	if ( right != NIL ) node[right].parent = id;
    }    

    for ( int i = 0; i < n; i++ ) {
	if ( node[i].parent == NIL ) {
	    root_id = i;
	    break;
	}
    }

    printf("Preorder\n");
    Preorder( root_id );
    printf("\n");

    printf("Inorder\n");
    Inorder( root_id );
    printf("\n");

    printf("Postorder\n");
    Postorder( root_id );
    printf("\n");


    return 0;
}


void Preorder(int id)
{
    printf(" %d", id);
    if ( node[id].left != NIL ) Preorder( node[id].left );
    if ( node[id].right != NIL ) Preorder( node[id].right );

    return;
}


void Inorder(int id)
{
    if ( node[id].left != NIL ) Inorder( node[id].left );
    printf(" %d", id);
    if ( node[id].right != NIL ) Inorder( node[id].right );

    return;
}


void Postorder(int id)
{
    if ( node[id].left != NIL ) Postorder( node[id].left );
    if ( node[id].right != NIL ) Postorder( node[id].right );
    printf(" %d", id);

    return;
}