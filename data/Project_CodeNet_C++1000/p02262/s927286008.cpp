#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

long long cnt;
int l;
int A[1000000];
int n;
vector<int> G;

void trace(int A[],int N) {
  int i;
  for(i=0; i<N; i++) {
    if(i>0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

void insertionSort(int A[],int N,int g) {
    int i, j, v;
  for(i=g; i<N; i++) {
    v=A[i]; /* v に関して記述 */
    j=i-g; /* j に関して記述 */
    while(j>=0 && A[j]>v) {
      A[j+g]=A[j];
      j-=g;
    	cnt++;
    }
    A[j+g]=v;
    //trace(A,N);
  }
}

void shellSort(int A[], int n) {
  for(int h=1; ;) {
    if(h>n) break;
  	G.push_back(h);
    h=h*3+1;
  }
	//debug
	//puts("G!!");
	//for(int i=0;i<G.size();i++)printf("%d,",G[i]);
	//puts("");//
	
  for(int i=G.size()-1; i>=0; i--) {
    insertionSort(A, n, G[i]);
  }
}

int main(void) {
  cin >> n;
  for(int i=0; i<n; i++) scanf("%d",&A[i]);
	cnt=0;

  shellSort(A,n);

	cout<<G.size()<<endl;
	 for(int i=G.size()-1; i>=0; i--) {
	 	printf("%d",G[i]);
	 	if(i)printf(" ");
	 }
	printf("\n%d\n",cnt);
  for(int i=0;i<n;i++) printf("%d\n",A[i]);

  return 0;
}