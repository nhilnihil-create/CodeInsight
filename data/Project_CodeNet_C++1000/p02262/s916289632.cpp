#include <stdio.h>
#include <vector>

using namespace std;

#define MAX_N (1000010)
int Array[MAX_N];
vector<int> G;

typedef long long int ll;

static
void
insertionSort( int A[], int n, int g );


static
void
shellSort( int A[], int n );


static
void
printArray( int A[], int n );

ll count = 0;

int main()
{
    int i;
    int N;
    scanf("%d", &N);
    for ( i = 0; i < N; i++ ) {
	scanf("%d", &Array[i]);
    }
    
    shellSort( Array, N );

    printf("%d\n", (int)G.size());

    for ( i = G.size() - 1; i >= 0; i-- ) {
	printf("%d%c", G[i], ( i == 0 ) ? '\n' : ' ' );
    }
    
    printf("%lld\n", count);
    
    printArray( Array, N );

    return 0;
}



static
void
insertionSort( int A[], int n, int g )
{
    int i;

    for ( i = g; i < n; i++ ) {
	int v = A[i];
	int j = i - g;
	
	while ( j >= 0 && A[j] > v ) {
	    A[j+g] = A[j];
	    j = j - g;
	    count++;
	}

	A[j+g] = v;
    }
}


static
void
shellSort( int A[], int n )
{
    int i;
    int h = 1;
    while ( true ) {
	if ( h > n ) break;
	G.push_back( h );
	h = 3 * h + 1;
    }
    
    for ( i = G.size() - 1; i >= 0; i-- ) {
	insertionSort( A, n, G[i] );
    }
    
}

static
void
printArray( int A[], int n )
{
    int i;
    for ( i = 0; i < n; i++ ) {
	printf("%d\n", A[i] );
    }
}