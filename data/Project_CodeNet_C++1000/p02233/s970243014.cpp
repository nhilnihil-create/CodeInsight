#include <stdio.h>
#include <iostream>
using namespace std;

class Fibonacci{
private:
	int f[45];
	int len;
public:
	Fibonacci(){ f[0] = f[1] = 1; len = 2; }
	int calc(int n);
};

int Fibonacci::calc(int n)
{
	if (n < len) return f[n];
	f[n] = calc(n - 1) + calc(n - 2);
	len++;
	return f[n];
}

int main(void)
{
	Fibonacci fib;
	int n;
	cin >> n;
	cout << fib.calc(n) << endl;
}