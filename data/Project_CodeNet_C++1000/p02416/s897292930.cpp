#include<stdio.h>
#include<string.h>

int main(){
	char number[1001]={0};
	int i,sum,lon;
	while(1){
	scanf("%s",number);
	if(strcmp(number,"0")== 0) break;
	lon = strlen(number);
		for(i=0;i<lon;i++){
			sum +=number[i]-'0';
		}
	printf("%d\n",sum);
	sum = 0;
	}
}