#include <stdio.h>
#include <string.h>

int main(){

int kalimat;
char input[100];
		
scanf("%d", &kalimat);
scanf("%s", input);

//masukin nya gimanee
int len = strlen(input);

//ok
for(int i = 0; i < len; i++){
			
    if(kalimat >= len){
		printf("%s", input);
		break;
	}
			
    else if(i < kalimat){
		printf("%c", input[i]);
	}
			
    else{printf("...\n");
		break;
	}
}
		
return 0;
}