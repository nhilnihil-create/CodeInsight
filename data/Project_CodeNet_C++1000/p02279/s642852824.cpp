#include <cstdio>
#include <vector>
#include <string>

using namespace std;

#define null -1

struct node{

    int parent, left, right;

};

node T[100005];
int Depth[100005];

void setDepth( int u, int p ){

    Depth[u] = p;

    if( T[u].right != null ){

        setDepth( T[u].right, p );

    }

    if( T[u].left != null ){

        setDepth( T[u].left, p + 1 );

    }

}

//??????????????¢??°

void print( int n){

    int i, j;

    for( i = 0; i < n; i++ ){

        printf("node %d: parent = %d, depth = %d, ", i, T[i].parent, Depth[i] );

        if( T[i].parent == null ) printf("root, ");
        else if( T[i].left == null ) printf("leaf, ");
        else printf("internal node, ");

        printf("[");

        j = T[i].left;

        while( j != null ){

            printf("%d", j );

            j = T[j].right;

            if( j == null ) break;

            printf(", ");

        }


        printf("]\n");

    }

}


int main(){

    int n, i, num, dim, j, bfr, l, root, v;

    scanf("%d", &n);

    for( i = 0; i < n; i++ ){

        T[i].left = null;
        T[i].right = null;
        T[i].parent = null;

    }

    for( i = 0; i < n; i++ ){

        scanf("%d %d", &num, &dim );

        for( j = 0; j < dim; j++ ){

            scanf("%d", &bfr);

            if( j == 0 ) T[num].left = bfr;
            else T[l].right = bfr;

            l = bfr;

            T[bfr].parent = num;

        }

    }

    for( i = 0; i < n ; i++ ){

        if( T[i].parent == null ) root = i;

    }



    setDepth( root, 0);

    print(n);

}