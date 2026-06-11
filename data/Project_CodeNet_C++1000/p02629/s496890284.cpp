#include <stdio.h>
#include <string.h>

int main(){
	char a[100];
	long long N, hb, sisa;
	scanf("%lld", &N);
	int j=0;
	while(1){
		hb=N/26;
		sisa=N%26;
		if(sisa==0){
			a[j]='z';
			hb-=1;
		}
		if(sisa!=0){
			a[j]=sisa-1+'a';
		}
		j++;
		if(hb==0){
			break;
		}
		N=hb;
	}
	a[j] = '\0';
	int len = strlen(a);
	for(int i=len-1; i>=0; i--){
		printf("%c", a[i]);
	}
	printf("\n");
	
	return 0;
}