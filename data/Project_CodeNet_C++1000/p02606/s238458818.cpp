#include <stdio.h>

int main(){
	
	int inp1, inp2, inp3, o=0;
	
	scanf("%d %d %d", &inp1, &inp2, &inp3);
	for(int i=inp1; i<=inp2; i++){
		if(i%inp3==0){
			o++;
		}
	}
	printf("%d\n", o);
	
	
	return 0;
}