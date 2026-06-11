#include <stdio.h>
int main (){
int N,flag= 0,j=0;
scanf("%d",&N);
char S [N];
scanf("%s",S);
for (int i =N/2;i < N; i++){
	if(N % 2 != 0){
		flag++;
		break;
	}else if (S[j] == S[i]){
		j++;
		
	}else {
		flag++;
		break;
	}
}
	flag != 0 ? puts ("No") : puts ("Yes");
	
	return 0;
}