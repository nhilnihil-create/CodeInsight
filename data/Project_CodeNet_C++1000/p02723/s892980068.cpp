#include<stdio.h>


 int main(){
 char S[7];
 scanf("%s", &S);
 if(S[2]==S[3] && S[4] == S[5]){
 	puts("Yes");
 }
 else{
 	puts("No");
 }
 return 0;
	}
