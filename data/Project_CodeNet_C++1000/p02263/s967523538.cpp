//逆波兰表达式，利用输入顺序及栈的特性 
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
#define maxx 1000
int stack[maxx];
//用数组实现栈，0号元素不使用 
int top;
/*int initialize()
{
	top=0;
}
bool isEmpty()
{
	return top==0;
}
bool isFull()
{
	return top<=maxx-1;
}
int push(int x)
{
	if(isFull)
		return -1;
	else{
		//top++;
		stack[++top]=x;
	}
}
int pop()
{
	int xx;
	if(isEmpty())
		return -1;
	else
	{
		top--;
		xx=stack[top+1];
		//xx=stack[top--];
	}
	return xx;
}
int look()
{
	return stack[top];
}
*/
void push(int x)
{
	stack[++top]=x;
}
int pop()
{
	top--;
	return stack[top+1];
}
int main()
{
	char s[100];
	int top=0;
	while(scanf("%s",s)!=EOF)
	{
		if(s[0]=='+')
		{
			int a=pop();
			int b=pop();
			//cout<<a<<" "<<b<<endl;
			push(a+b);
		}
		else if(s[0]=='-')
		{
			int a=pop();
			int b=pop();
			//cout<<a<<" "<<b<<endl;
			push(b-a);
		}
		else if(s[0]=='*')
		{
			int a=pop();
			int b=pop();
			//cout<<a<<" "<<b<<endl;
			push(a*b);
		}
		else
		{
			//cout<<atoi(s)<<endl;
			push(atoi(s));//atoi标准库中的函数，用来将字符串形式的数字转换为整型数值 
		} 
	}
	int result=pop();
	cout<<result<<endl;
	return 0;
}
