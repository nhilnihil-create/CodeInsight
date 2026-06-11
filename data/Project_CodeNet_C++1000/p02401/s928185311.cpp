// class point	の練習（クラスの高度な実装）
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;



int main() {
	int a, b;
	char op[2] = "+";
	while (1) {
		cin >> a >>  op[0]  >> b;
		if (strcmp(op, "?") == 0) {
			break;
		}
		else if (strcmp(op, "+") == 0)cout << a + b << endl;
		else if (strcmp(op, "-") == 0)cout << a - b << endl;
		else if (strcmp(op, "*") == 0)cout << a * b << endl;
		else if (strcmp(op, "/") == 0)cout << a / b << endl;
	}
	


	return 0;
}

