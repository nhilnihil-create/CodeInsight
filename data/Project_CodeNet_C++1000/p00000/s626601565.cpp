#include<stdio.h>
int main(void)
{
    int i,n,a;
	a=0;
	
	for(i=1;i<10;i++){
	    for(n=1;n<10;n++){
		    a=i*n;
			printf("%dx%d=%d\n",i,n,a);
		}
	}
	return 0;
}