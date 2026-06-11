#include<iostream>
#define NIL -1

struct Node
{
    int parent, left_child, right_sibling ;
} ;

Node tree[100001] ;
int depth[100001] ;

void print_node( int u )
{
    std::cout << "node " << u << ": " ;
    std::cout << "parent = " << tree[u].parent <<", " ;
    std::cout << "depth = " << depth[u] << ", " ;
    if( tree[u].parent == NIL )
    {
        std::cout << "root, " ;
    }
    else if( tree[u].left_child == NIL )
    {
        std::cout << "leaf, " ;
    }
    else
    {
        std::cout << "internal node, " ;
    }
    std::cout << "[" ;
    for( int c = tree[u].left_child, flag = 0 ; c != NIL ; c = tree[c].right_sibling )
    {
        if( flag ) 
        {
            std::cout << ", " ;
        }
        std::cout << c ;
        flag = 1 ;
    }
    std::cout << "]" << std::endl ; 
}

void make_depth( int root, int stone = 0 )
{
    depth[root] = stone ;
    if( tree[root].right_sibling != NIL )
    {
        make_depth( tree[root].right_sibling, stone ) ;
    }
    if( tree[root].left_child != NIL )
    {
        make_depth( tree[root].left_child , stone+1 ) ;
    }

}

int main()
{
    int n ; 
    std::cin >> n ;
    for( int i = 0 ; i < n ; ++i )
    {
        tree[i].parent = tree[i].left_child = tree[i].right_sibling = NIL ; 
    }
    int a, b, c, d ;
    for( int i  = 0 ; i < n ; ++i )
    {
        std::cin >> a >> b ;
        for( int j = 0 ; j < b ; ++j )
        {
            std::cin >> c ;
            if( j == 0 )
            {
                tree[a].left_child = c ;
            }
            else
            {
                tree[d].right_sibling = c ;
            }
            d = c ;
            tree[c].parent = a ;
        }
    }
    int root ;
    for( int i = 0 ; i < n ; ++i )
    {
        if( tree[i].parent == NIL )
        {
            root = i ;
        }
    }

    make_depth( root ) ;
    for( int i = 0 ; i < n ; ++i )
    {
        print_node( i ) ;
    }
    return 0 ;
}

