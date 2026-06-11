#include<stdio.h>
main(){
	int a,b;
	int answer;
	char op;

	while(1){
		scanf("%d %c %d",&a,&op,&b);
	if(op == '+'){
		answer = a + b;
		printf("%d\n",answer);
	}
	else if (op == '-'){
		answer = a - b;
		printf("%d\n",answer);
	}
	else if (op == '*'){
		answer = a * b;
		printf("%d\n",answer);
	}
	else if (op == '/'){
		answer = a / b;
		printf("%d\n",answer);
	}
	else break;
	}

	return 0;
}