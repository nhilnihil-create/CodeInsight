#include <iostream>
#include <string>
#include <stack>
#include <cmath>

int c2i(char c) {
	switch (c) {
	case '0': return 0;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	default: return -1;
	}
}

int str2i(std::string str) {
	int x = 0;
	for (int i = 0; i < str.size(); i++)
		x += c2i(str[str.size()-1 -i]) * std::pow(10,i);
	return x;
}


int main() {
	std::string in;
	std::stack<int> s;
	while (std::cin >> in) {
		if (in == "+" || in == "-" || in == "*" || in == "/") {
			char op = in[0];
			int b = s.top();
			s.pop();
			int a = s.top();
			s.pop();
			switch (op) {
			case '+':
				s.push(a + b);
				break;
			case '-':
				s.push(a - b);
				break;
			case '/':
				s.push(a / b);
				break;
			case '*':
				s.push(a * b);
				break;
			}
		}
		else 
			s.push(str2i(in));
		//std::cout << s.top() << std::endl;
	}
	std::cout << s.top() << std::endl;


	return 0;
}