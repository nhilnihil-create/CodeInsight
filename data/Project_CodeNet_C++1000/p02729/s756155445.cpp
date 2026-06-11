#include<stdio.h>


 int main(){
 int N,M;
 int A = 0,B = 0;
 scanf("%d %d",&N ,&M);
 for(int i = 1; i < N; i++){
 		A += i;
 	
 }
 for(int i = 1; i < M; i++){
 		B += i;
 	
 }
  printf("%d",A + B );
  return 0;
	}
	
