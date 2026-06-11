// http://algorithms.blog55.fc2.com/blog-entry-66.html

#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>

#define MAX 100

int SIZE;
int R[MAX + 2];
int C[MAX+1][MAX+1]; // cost table
int B[MAX+1][MAX+1]; // best table

void compute(){
	int i=0,j,k;
	memset(C,99,sizeof(C));
    
    for (i = 0; i < SIZE; i++ ) C[i][i] = 0;
    
    for (j = 1; j < SIZE; j++ ){
        for (i = 0; i < SIZE - j; i++ ){
            for (k = i; k < i + j; k++ ){
                // C[i][i+j] = min( C[i][i+j], 
                //                  C[i][k-1] + C[k][i+j] + R[i]*R[k]*R[i+j+1]);
                int cost = C[i][k] + C[k+1][i+j] + R[i]*R[k+1]*R[i+j+1];
                if ( cost < C[i][i+j] ){
                    C[i][i+j] =  cost;
                    B[i][i+j] = k;
                }
                
            }
        }
    }
}

void order( int i, int j ){
    if ( i == j ) cout << "M" << i;
    else{
        cout << "(";
        order( i, B[i][j]-1 ); order(B[i][j], j);
        cout << ")";
    }
}

void input(){
    cin >> SIZE;
	int z,i=0;
    for (; i < SIZE; i++ ) cin >> R[i]>>z;
	R[i]=z;
	//SIZE++;
}

void output(){
    cout <<  C[0][SIZE-1] << endl;
    //order(1, SIZE);
    //cout << endl;
}

main(){
    input();
    compute();
    output();
}