#include <iostream>

using namespace std;


int fibonacci(int n)
{
	int preFib = 1;
	int prepreFib = 1;
	int fib;

	if (n <= 1) {
		return 1;
	}

	for (int i = 2; i <= n; i++) {
		fib = preFib + prepreFib;
		prepreFib = preFib;
		preFib = fib;
	}

	return fib;

}

int main(void)
{
	int n;
	cin >> n;
	cout << fibonacci(n) << endl;

	return 0;
}