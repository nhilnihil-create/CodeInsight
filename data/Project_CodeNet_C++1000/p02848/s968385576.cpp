#include <stdio.h>
#include <string.h>
int main(){
	int N;
	scanf("%d",&N);
	char zz[10000];
	scanf("%s",zz);
	int len = strlen(zz);
	char hasil[len];
	for (int i=0;i<len;i++){
		hasil[i] = zz[i]+N;
		if (hasil[i]>'Z'){
			hasil[i] -=26;
		}
	}
	for(int i=0;i<len;i++){
		printf("%c",hasil[i]);
	}
return 0;
}