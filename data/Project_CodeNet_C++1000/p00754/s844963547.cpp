#include <stdio.h>

int closejudge(char tmp,char *c){
	int flag = 0;
	char wtmp, retmp;
	if(tmp == ')')
		wtmp = ']';
	else
		wtmp = ')';
	*c = getchar();
	while(*c != tmp && flag == 0){
		if(*c == '.' || *c == wtmp)
			flag = 1;
		else if(*c == '(' || *c == '['){
			if(*c == '(')
				retmp = ')';
			else
				retmp = ']';
			flag = closejudge(retmp,c);
		}
		if(*c != '.')
			*c = getchar();
	}
	return flag;
}
int main(void){
	char c,tmp;
	int flag;
	c = getchar();
	while(c != '.'){
		flag = 0;
		while(c != '.' && flag == 0){
			if(c == ')' || c == ']')
				flag = 1;
			if(c == '(' || c == '['){
				if(c == '(')
					tmp = ')';
				else
					tmp = ']';
				flag = closejudge(tmp,&c);
			}
			if(c != '.')
				c = getchar();
		}
		while(c != '\n')
			c = getchar();
		if(flag == 0)
			printf("yes\n");
		else
			printf("no\n");
		c = getchar();
	}
	return 0;
}