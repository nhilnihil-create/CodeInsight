#include<stdio.h>
#include<string.h>

int main(){
	int multiples,low,high;
	scanf("%d",&multiples);
	getchar();
	scanf("%d%d",&low,&high);
	bool found = true;
	for(int i=low;i<=high;i++){
		if(i%multiples == 0){
			printf("OK\n");
			found=false;
			break;
		}
	}
	if (found) printf("NG\n");
	return 0;
}