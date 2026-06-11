#include<iostream>
#include <cstdio>
using namespace std;

int main(){
	int a,b,c;
	char op;
	
	while(1){
		scanf("%d%s%d",&a,&op,&b);
		if( op == '+' ){
			c=a+b;
		}else if( op == '-' ){
			c=a-b;
		}else if( op == '*' ){
			c=a*b;
		}else if( op == '/' ){
			c=a/b;
		}else if( op == '?' ){
			break;
		}

		cout << c << "\n";

	}
	
	
	return 0;
	
}