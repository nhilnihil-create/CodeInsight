#include <stdio.h>

int main(){
	int kiri, kanan, pembagi;
	int output = 0;	
	scanf("%d %d %d", &kiri, &kanan, &pembagi);
	
	for (int i=kiri; i<=kanan; i++){
		if(i%pembagi==0){
			output++;

		}
	}
	printf("%d", output);
	
	return 0;
}
