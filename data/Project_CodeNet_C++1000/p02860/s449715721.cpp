#include <stdio.h>
#include <string.h>
int main(){
int n;
scanf("%d",&n);
char chara[n];
scanf("%s",chara);
int len=strlen(chara);
if(len%2){
	printf("No");
	return 0;
}
else{
	for (int i=0;i<len/2;i++){
		if(chara[i]!=chara[i+(len/2)]){
			printf("No");
			return 0;
		}
		else{
			continue;
		}
	}
}
printf("Yes");
return 0;
}