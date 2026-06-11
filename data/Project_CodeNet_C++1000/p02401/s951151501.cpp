#include <stdio.h>

int main(void)
{
	int a,b,d,e[10000],f;
	char c;
	c = '+';
	d = 0;
	
	while(c != '?'){
		scanf("%d %c %d",&a,&c,&b);
		if(c == '+'){
			e[d] = a+b;
			++d;
		}
		else if(c == '-'){
			e[d] = a-b;
			++d;
		}
		else if(c == '*'){
			e[d] = a*b;
			++d;
		}
		else if(c == '/'){
			if(a != 0 || b != 0){
				e[d] = a/b;
				++d;
			}
		}
	}
	
	for(f = 0; f < d;++f){
		printf("%d\n",e[f]);
	}
	
	return(0);
}