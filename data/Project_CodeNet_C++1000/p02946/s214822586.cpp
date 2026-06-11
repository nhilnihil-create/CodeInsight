#include <iostream>
using namespace std;

int main()
{
	int k, x,n;
	cin >> k >> x;
	x = x - k;
	for (size_t i = 0; i < (2*k-1); i++)
	{
		x = x + 1;
		cout << x << " ";
	}
}
