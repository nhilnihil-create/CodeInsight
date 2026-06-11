#include <stdio.h>

int main(void)
{
	int a,b,c,d,e[10000],f[10000],h,g,i,j;
	a = b = 1;
	h = g = 0;
	
	while(a != 0 && b != 0){
		scanf("%d %d",&a,&b);
		
		e[h] = a;
		f[g] = b;
		
		++g;
		++h;
		j = h;
	}
	g = h = 0;
	
	for(i = 0;i < j;++i){
		for(c = 0;c < e[g-1];++c){
			for(d = 0;d < f[h-1];++d){
				if(c == 0 || c == e[g-1]-1){
					printf("#");
				}
				else if(d == 0 || d == f[h-1]-1){
					printf("#");
				}
				else {
					printf(".");
				}
			}
			printf("\n");
		}
		if(c != 0){
			printf("\n");
		}
		++g;
		++h;
	}
	
	return(0);
}