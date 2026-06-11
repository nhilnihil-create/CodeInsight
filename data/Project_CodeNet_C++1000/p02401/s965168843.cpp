#include<iostream>
using namespace std;	

int main(){
	int a, b;
	char op;
	int ans;
	while (1){
		cin >> a >> op >> b;
		if (op == '?') break;
		switch (op){
		case '+':
			ans = a + b;
			break;
		case '-':
			ans = a - b;
			break;
		case '*':
			ans = a * b;
			break;
		case '/':
			ans = a / b;
			break;
		default:
			break;
		}
		cout << ans << endl;
	}
	return 0;
}