#include <stdio.h>

int main(){
	int idx=0;
	scanf("%d", &idx);
	char str[idx+1];
	scanf("%s", &str);
	if(idx%2==1){
		puts("No");
	}
	else{
		int tanda = 1;
		
		for(int i=0; i < idx/2; i++){
			if(str[i] != str[i + idx/2]){
				tanda = 0;
			}
		}
		if(tanda==1){
			puts("Yes");
		}
		else{
			puts("No");
		}
	}
	
	return 0;
}