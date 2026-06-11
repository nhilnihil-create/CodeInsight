#include <stdio.h>
int main(){
int input;



scanf("%d", &input);
int hasil=0, klr=0;
for (int i=1;i<=9;i++){
	
	for (int j=1;j<=9;j++){
		
		if(input==i*j){
			klr++;
			break;
		}
		else{
			hasil++;
	
		}
	}
	if(klr==1){
		puts("Yes");
		break;
	}	
}
if(hasil==81){
	puts("No\n");
}

return 0;
}