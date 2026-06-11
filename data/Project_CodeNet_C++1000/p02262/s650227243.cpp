#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

//?¢????????????¨???????????°?????????

int N;
int A[100000000];
long long cnt;
vector<int> G;

//???????????????????????¢??° write ?????????

void write( int A[], int N ){

    for( int i = 0 ; i < N ; i++ ){

        if( i > 0 ){

            printf("\n");
            
        }

        printf("%d", A[i] );

    }

    printf("\n");

}

// insertion_sort?????????

void insertion_sort( int A[], int N, int g){

    int i, j, v ;

    for( i = g ; i < N ; i++ ){

        v = A[i];
        j = i - g;

        while( j >= 0 && A[j] > v ){

            A[j + g] = A[j] ;
            j = j - g;
            cnt++;

        } 

        A[ j + g ] = v;

    }

}

// shell_sort?????????

void shell_sort( int A[], int N ){

    int i, h;

    for( h = 1 ;;){

        if( h > N ) break;

        G.push_back(h);

        h = 3*h + 1;

    }

    for( i = G.size() - 1 ; i >= 0 ; i-- ){

        insertion_sort( A, N, G[i] );

    }

}

//??¬???

int main(){

    int i;

    cnt = 0;

    scanf("%d", &N);
 
    for( i = 0 ; i < N ; i++ ){
 
        scanf( "%d", &A[i] );
 
    }
 
    shell_sort( A, N);

    printf("%d\n", G.size() );

    for( i = G.size() - 1 ; i >= 0 ; i-- ){

        if( i < G.size() - 1 ) printf(" ");

        printf("%d", G[i]);

    }

    printf("\n");

    printf("%d\n", cnt);

    write( A, N);

    return 0;

}