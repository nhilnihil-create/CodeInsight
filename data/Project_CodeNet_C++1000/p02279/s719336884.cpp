#include <iostream>
using namespace std;

#define MAX 100000+5
#define NIL -1

struct Node {
    int parent;
    int left;
    int right;
};

Node T[MAX];
int n, D[MAX];

void Print( int u );
int Rec( int u, int p );

int main() {
    cin >> n;
    for ( int i = 0; i < n; ++i ) T[i].parent = T[i].left = T[i].right = NIL;
    
    int v, d, l;
    for ( int i = 0; i < n; ++i ) {
        cin >> v >> d;
        int c;
        for ( int j = 0; j < d; ++j ) {
            cin >> c;
            if ( 0 == j ) T[v].left = c;
            else T[l].right = c;
            l = c;
            T[c].parent = v;
        }
    }
    
    int r;
    for ( int i = 0; i < n; ++i ) {
        if ( T[i].parent == NIL ) {
            r = i;
        }
    }
    
    Rec( r, 0 );
    
    for ( int i = 0; i < n; ++i ) Print( i );
    
    return 0;
}

void Print( int u ) {
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].parent << ", ";
    cout << "depth = " << D[u] << ", ";
    
    if ( NIL == T[u].parent ) cout << "root, ";
    else if ( NIL == T[u].left ) cout << "leaf, ";
    else cout << "internal node, ";
    
    cout << "[";
    int flag = 0;
    for ( int c = T[u].left; c != NIL; c = T[c].right ) {
        if ( flag++ ) cout << ", ";
        cout << c;
    }
    cout << "]\n";
}

int Rec( int u, int p ) {
    D[u] = p;
    if ( NIL != T[u].right ) Rec( T[u].right, p );
    if ( NIL != T[u].left ) Rec( T[u].left, p+1 );
}