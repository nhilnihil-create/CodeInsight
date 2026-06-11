#include <iostream>

int main()
{
	while (true){
	int a, b;
	char op;
	std::cin >> a >> op >> b;
	switch (op)
	{
	case '+':
		std::cout << a + b << std::endl;
		break;
	case '-':
		std::cout << a - b << std::endl;
		break;
	case '*':
		std::cout << a * b << std::endl;
		break;
	case '/':
		std::cout << a / b << std::endl;
		break;
	case '?':
		return 0;
	}
}
	return 0;
}