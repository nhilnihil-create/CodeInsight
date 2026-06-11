#include <stdio.h>
#include <string.h>

int main(){
	int x,y;
	scanf("%d",&x);
	char a[10000];
	scanf("%s",a);
	int len=strlen(a);
	for(int i=0; i<len;i++){
		a[i]+=x;
		if(a[i]>'Z'){
			a[i]-=26;
		}
		printf("%c",a[i]);
	}
	return 0;
}