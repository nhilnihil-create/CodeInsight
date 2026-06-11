#include <stdio.h>
#include <string>
#include <math.h>
#include <iostream>
using namespace std;
#define N 1000
void push(int x);	//
int pop(void);		//
int isEmpty(void);	//
int isFull(void);
void initialize(void);
static int S[N], top = 0;
int main(void)
{
	char op[13];
	int x,a, b, cou = 0;
	while(scanf("%s",op) != EOF){
		switch (op[0]) {
			case '+': a = pop(); b = pop(); push(b + a); break;
			case '-': a = pop(); b = pop(); push(b - a); break;
			case '*': a = pop(); b = pop(); push(b * a); break;
			case '/': a = pop(); b = pop(); push(b / a); break;
			default: sscanf(op, "%d", &x); push(x);
		}
	}
	printf("%d\n", pop());
}
void push(int x)
{
	if (!(isFull())) {
		top++;
		S[top] = x;
	}
}
int pop(void)
{
	if (!(isEmpty())) {
		top--;
		return (S[top + 1]);
	}
}
int isEmpty(void) 
{
	if (top == 0) return 1;
	else return 0;
}
int isFull(void)
{
	if (top >= N - 1) return 1;
	else return 0;
}
void initialize(void)
{
	top = 0;
}