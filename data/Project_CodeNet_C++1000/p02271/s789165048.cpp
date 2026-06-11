#include <stdio.h>
int solve(int,int);
int A[20],s;
int n,q;
int main(){

  //int n,q;
  int i,j=0;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    scanf("%d",&A[i]);

  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&s);
    j=0;

    if(solve(j,s)==1)
      printf("yes\n");

    if(solve(j,s)==0)
      printf("no\n");
  }
  return 0;
}

int solve(int i,int m){

  int res;

  if(m==0)return 1;

  else if(i>=n)return 0;
  res=solve(i+1,m)||solve(i+1,m-A[i]);
}