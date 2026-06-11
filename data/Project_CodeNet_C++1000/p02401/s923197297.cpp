#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	int a, b;
	char op;

	while(1){
		scanf("%d %c %d", &a, &op, &b);
		if(op == '?')      break;
		else if(op == '+') cout<<a+b<<endl;
		else if(op == '-') cout<<a-b<<endl;
		else if(op == '*') cout<<a*b<<endl;
		else if(op == '/') cout<<a/b<<endl;
	}

	return 0;
}