#include<iostream>
#include<cstdio>
#include<cassert>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

long long cnt;
int l;
int A[1000000];
int B[1000000];
int N;
vector<int> G;

void insertionSort(int A[], int N, int g){
  for ( int i = g; i < N; i++ ){
    int v = A[i];
    int j = i - g;
    while( j >= 0 && A[j] > v ){
      A[j+g] = A[j];
      j -= g;
      cnt++;
    }
    A[j+g] = v;
  }
}

void shellSort(int A[], int N){

  for ( int h = 1; ;  ){
    if ( h > N ) break;
    G.push_back(h);
    h = 3*h + 1;
  }

  for ( int i = G.size()-1; i >= 0; i-- ){
    insertionSort(A, N, G[i]);
  }
}

main(){
  cin >> N;
  for ( int i = 0; i < N; i++ ) scanf("%d", &A[i]);
  for ( int i = 0; i < N; i++ ) B[i] = A[i];
  cnt = 0;
  shellSort(A, N);
  sort(B, B+N);
  //  for ( int i = 0; i < N; i++ ) assert(A[i] == B[i]);

  cout << G.size() << endl;
  for ( int i = G.size()-1; i >= 0; i-- ){
    printf("%d", G[i]);
    if ( i ) printf(" ");
  }
 printf("\n");
  printf("%d\n", cnt);
  for ( int i = 0; i < N; i++ ) printf("%d\n", A[i]);
}

