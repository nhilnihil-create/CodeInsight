#include<stdio.h>

int main(){
    
	int len;
	
	scanf("%d",&len);
	char str[len+5];
	scanf("%s",&str);
	if(len % 2 != 0){
		printf("No\n");
	}
	else{
		int left = 0, right = 0;
		
		for(int i = 0;i<len;i++){
			if(i<len/2) left+=str[i];
			else if (i>=len/2) right+=str[i];
		}
		
		if(right == left) printf("Yes\n");
		else printf("No\n");		
	}
	
	return 0;
}