#include <stdio.h>

int main(void)
{
	int a,b;
	char op;
	int ans;
	int loop=1;
	while(loop){
	scanf("%d %c %d",&a, &op, &b);
	switch(op){
		case '+': ans = a+b; break;
		case '-': ans = a-b; break;
		case '*': ans = a*b; break;
		case '/': ans = a/b; break;
		case '?': break;
	}
	if(op != '?'){
	printf("%d\n",ans);
	}else{
		loop=0;
	}
	}
	return 0;
}