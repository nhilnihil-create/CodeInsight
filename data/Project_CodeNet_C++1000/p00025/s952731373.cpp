#include<iostream>
#include<cstdio>

int A[4];
int B[4];
int main()
{
  while(scanf("%d %d %d %d\n%d %d %d %d",&A[0],&A[1],&A[2],&A[3],&B[0],&B[1],&B[2],&B[3]) != EOF){
  int Hit = 0;
  int Blow = 0;
  for(int i = 0;i < 4;i++){
    for(int j = 0; j < 4;j++){
      if(A[i] == B[j]){
	if(i ==j){
	  Hit++;
	}else
	  Blow++;
      }
    }
  }
    printf("%d %d\n",Hit,Blow);
  }
  return 0;
}