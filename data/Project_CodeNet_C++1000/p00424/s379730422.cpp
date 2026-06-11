#include<stdio.h>

int main(){
	int c[256];
	int a;
	while(1){
		scanf("%d",&a);
		if(a==0)return 0;
		for(int i=0;i<256;i++)c[i]=i;
		getchar();
		getchar();
		for(int i=0;i<a;i++){
			char b,d;
			b=getchar();
			getchar();
			d=getchar();
			getchar();
			getchar();
			c[b]=d;
		}
		int e;
		scanf("%d",&e);
		getchar();
		getchar();
		char f;
		for(int i=0;i<e;i++){
			f=getchar();
			getchar();
			getchar();
			putchar(c[(int)f]);
		}
		printf("\n");
	}
}