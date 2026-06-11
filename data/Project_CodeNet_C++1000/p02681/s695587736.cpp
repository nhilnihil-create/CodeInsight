#include <stdio.h>
#include <string.h>

int main() {
	char kata1[15];
	char kata2[16];
	scanf("%s",kata1);
	scanf("%s",kata2);
	int str = strlen(kata1);
	int a = 0,count = 0;
	for(a = 0; a<str; a++){
		if(kata1[a] == kata2[a]){
			count++;	
		}
	}
	if(count == str){
		printf("Yes\n");
	}else{
		printf("No");
	}		
	return 0;
}
