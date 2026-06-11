#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
	int a, b = 0;
	char op[5];
	while (true){
		cin >> a >> op >> b;
		if (op[0] == '+'){
			cout << a + b << endl;
		}
		else if (op[0] == '-'){
			cout << a - b << endl;
		}
		if (op[0] == '*'){
			cout << a*b << endl;
		}
		if (op[0] == '/'){
			cout << a / b << endl;
		}
		if (op[0] == '?'){
			break;
		}
	}
	return 0;
}