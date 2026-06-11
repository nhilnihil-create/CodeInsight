#include<stdio.h>
#include<string.h>
int main(){
	int a, b, bagi;	
	int hasil=0;
		scanf("%d%d%d", &a, &b, &bagi);
		
		for(int i=a;i<=b;i++){
			if(i%bagi==0){
				hasil++;
			}
		}
		printf("%d\n", hasil);
	
	return 0;
}