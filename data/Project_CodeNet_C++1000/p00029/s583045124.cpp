#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	int l=0,i=0,ls[64],max=0;
	char bun[64][64],mo[64];
	while(scanf("%s",bun[i])!=EOF){
		for(int j=0;j<strlen(bun[i]);j++){
			if(isupper(bun[i][j])){
				bun[i][j]=tolower(bun[i][j]);
			}
		}
		if(strlen(bun[i])>l){
			l=strlen(bun[i]);
			strcpy(mo,bun[i]);
		}
		i++;
	}
	for(int j=0;j<i-1;j++){
		for(int k=0;k<i-1;k++){
			if(k!=j){
				if(strcmp(bun[k],bun[j])==0){
					ls[j]++;
				}
			}
		}
	}
	for(int j=0;j<i;j++){
		if(ls[max]<=ls[j]){
			max=j;
		}
	}
	printf("%s %s\n",bun[max+1],mo);
	return 0;
}