#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

long long cnt;
int i;
int a[1000000];
int n;
vector<int> G;

//???????????´???g????????\??????
void InsertionSort( int a[], int n, int g ) {
	for ( int i = g; i < n; i++ ) {
        int v = a[i];
        int j = i - g;
        while ( j >= 0 && a[j] > v ) {
            a[j+g] = a[j];
            j -= g;
            cnt++; 
        }
        a[j+g] = v;
    }
} 

void ShellSort( int a[], int n ) {
    //????????°???G = {1, 4, 13, 40, 121, ...}
    int h = 1;
    while ( true ) {
        if ( h > n ) {
            break;
        }
        G.push_back(h);
        h = 3*h + 1;
    }
    
    for ( int i = G.size()-1; i >= 0; i-- ) {
        InsertionSort( a, n, G[i] );
    }
}

int main() {
    scanf( "%d", &n );
    for ( int i = 0; i < n; i++ ) scanf( "%d", &a[i] );
    cnt = 0;
    
    ShellSort( a, n );
    
    printf( "%d\n", G.size() );
    for ( int i = G.size()-1; i >= 0; i-- ) {
        printf( "%d", G[i] );
        if ( i ) {
            printf( " " );
        }
    }
    printf( "\n" );
    printf( "%d\n", cnt );
    for ( int i = 0; i < n; i++ ) {
        printf( "%d\n", a[i] );
    }
    
	return 0;
} 