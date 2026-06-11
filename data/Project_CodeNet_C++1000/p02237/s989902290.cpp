#include<iostream>
#include<cstdio>
#define N 101
using namespace std;

int main(){

  int n,n2,data,u;
  int g[N][N]; 
 //load n
  cin >>n;

  //initialize
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      g[i][j]=0;
    }
  }

  for(int i=0;i<n;i++){
    scanf("%d%d",&u,&n2);
    for(int j=0;j<n2;j++){
      scanf("%d",&data);
      g[u][data]=1;
    }
  }

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      printf("%d",g[i][j]);
      if(j!=n)printf(" ");
    }
    printf("\n");
  }

  return 0;
}