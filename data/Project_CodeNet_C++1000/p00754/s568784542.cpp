#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int stack[50000];
int size=0;
int main(void){
	while(1){
		char c;
		int flag=0;
		size=0;
		int flag2=1;
		while((c=getchar())!='.'){
			flag=1;
			if(!flag2)continue;
			if(c=='(')stack[size++]=1;
			if(c=='[')stack[size++]=2;
			if(c==')'){
				if(size==0)flag2=0;
				else{
					size--;
					if(stack[size]!=1)flag2=0;
				}
			}
			if(c==']'){
				if(size==0)flag2=0;
				else{
					size--;
					if(stack[size]!=2)flag2=0;
				}
			}
		}
		c=getchar();
		if(!flag)break;
		if(size!=0)flag2=0;
		printf("%s\n",flag2?"yes":"no");
	}
	return 0;
}