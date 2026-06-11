#include <iostream>
using namespace std;
int main(){
	char buf[110],stack[110]={0},*sp,*p;
	while(fgets(buf,103, stdin),*buf!='.'){
		sp=stack+1;
		p=buf;
		for(;*p!='.';p++){
			if(*p == '(' || *p == '['){
				*sp++ = *p;
			}else if(*p == ')' || *p == ']'){
				sp--;
				if(!((*sp =='(' && *p == ')') || (*sp =='[' && *p == ']'))){
					puts("no");
					break;
				}
			}
		}
		if(*p=='.')puts(sp==stack+1?"yes":"no");
	}
}