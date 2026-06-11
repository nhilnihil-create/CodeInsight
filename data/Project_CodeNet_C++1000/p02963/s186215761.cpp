#include <iostream>
using namespace std;

long long s;
long long a, b;

int main()
{
	cin >> s;
	a = s % 1000000000;
	b = s / 1000000000;
	if (a)
	{
		cout << 0 << ' ' << 0 << ' ' << 1000000000 - a << ' ' << b + 1 << ' ' << 1000000000 << ' ' << 1 << endl;
	}
	else
	{
		cout << 0 << ' ' << 0 << ' ' << 0 << ' ' << b << ' ' << 1000000000 << ' ' << 1 << endl;
	}
	
}