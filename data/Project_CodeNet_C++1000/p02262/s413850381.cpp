#include<stdio.h>
int cnt,m,G[101];

int insertionSort(int *A, int n, int g){
  int i;
  for (i = g ;i< n;i++){
          int v = A[i];
          int j = i - g;
          while( j >= 0 && A[j] > v){
              A[j+g] = A[j];
              j = j - g;
              cnt++;
            }
          A[j+g] = v;
        }
}



void shellSort(int *A, int n){
     cnt = 0;
     int x=0;
     while(1){
       x=x*3+1;
       if(x>n)break;
       G[m++]=x;
     }
     int i;
     for (i = 0 ;i< m;i++)insertionSort(A, n, G[m-i-1]);
}




int main(){
  int n;
  scanf("%d",&n);
  int A[n],i;
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  shellSort(A,n);
  printf("%d\n",m );
  for(i=m-1;i>=0;i--){
    if(i!=0)printf("%d ",G[i]);
    else printf("%d\n%d\n",G[i],cnt );
  }
  for(i=0;i<n;i++)printf("%d\n",A[i] );
  return 0;
}

