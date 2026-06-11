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
	
	for(i = 1;i < j;++i){
		for(c = 1;c <= e[g];++c){
			if(c % 2 == 1){
				for(d = 1;d <= f[h];++d){
					if(d % 2 == 1){
						printf("#");
					}
					else if(d % 2 == 0){
						printf(".");
					}
				}
			}
			else if(c % 2 == 0){
				for(d = 1;d <= f[h];++d){
					if(d % 2 == 1){
						printf(".");
					}
					else if(d % 2 == 0){
						printf("#");
					}
				}
			}
				
			printf("\n");
		}
		printf("\n");
		++h;
		++g;
	}
	
	return(0);
}