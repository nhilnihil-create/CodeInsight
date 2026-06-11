#include <iostream>

using namespace std;

unsigned long long int a, b;

unsigned long long int gcd(unsigned long long int a, unsigned long long int b)
{
	if (a%b == 0)
	{
		return(b);
	}
	else
	{
		return(gcd(b, a%b));
	}
}

unsigned long long int lcm(unsigned long long int a, unsigned long long int b)
{
	return a * b / gcd(a, b);
}

int main()
{
	unsigned long long int a, b;
	cin >> a >> b;

	//cout << "最大公約数:" << gcd(a, b) << endl;
	cout << lcm(a, b) << endl;
	return 0;
}