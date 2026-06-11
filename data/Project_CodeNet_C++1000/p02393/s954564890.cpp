#include<stdio.h>

int main(void)
 {
	int a, b, c;
	scanf("%d %d %d",&a ,&b ,&c);
	if(a<b){
		if(b<c){
			printf("%d %d %d\n",a, b, c);
			return 0;
		}
		if(c<b){
			printf("%d %d %d\n",a, c, b);
			return 0;
		}
	}
	if(b<c){
		if(c<a){
			printf("%d %d %d\n",b, c, a);
			return 0;
		}
		if(a<c){
			printf("%d %d %d\n",b, a, c);
			return 0;
		}
	}
	if(c<a){
		if(a<b){
			printf("%d %d %d\n",c, a ,b);
			return 0;
		}
		if(b<a){
			printf("%d %d %d\n",c, b, a);
			return 0;
		}
	}
 }