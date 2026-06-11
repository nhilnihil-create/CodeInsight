#include <iostream>
using namespace std;

int main() {
	int a, b;
	char op;
	while (true) {
		cin >> a >> op >> b;
		if (op == '?') break;
		int sum = 0;
		switch (op) {
		case '+': sum = a + b;
			break;
		case '-': sum = a - b;
			break;
		case '*': sum = a * b;
			break;
		case '/': sum = a / b;
			break;
		case '?': break;
		}
		cout << sum << endl;
	}
	return 0;
}