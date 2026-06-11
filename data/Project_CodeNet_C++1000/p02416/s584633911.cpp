#include<stdio.h>
#include<string.h>
int main(){
	char ang[1010];
	int sum;
	while(scanf("%s",ang) != EOF){
		if(strcmp(ang, "0")==0) break;
		for(int i=0; i<strlen(ang); i++){
			sum = sum + ang[i]-'0';
		}
		printf("%d\n",sum);
		sum=0;
	}
}
