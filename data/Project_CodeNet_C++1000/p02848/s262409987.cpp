#include<stdio.h>
#include<string.h>

typedef long long ll;

int main(){
	char x[10005];
	int n;
	scanf("%d",&n);
	getchar();
	scanf("%s",x);
	int len = strlen(x);
	for(int i=0;i<len;i++){
		if(x[i]+n>90)
			x[i]-=26;
		printf("%c",x[i]+n);
	}
}