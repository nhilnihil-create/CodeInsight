#include<iostream>
using namespace std;

int main()
{
	int a;
	int b;

	cin >> a;

	b = a % 10;

	if (b == 3)cout << "bon";

	else if (b == 0 || b == 1 || b == 6 || b == 8)cout << "pon";

	else cout << "hon";

	return 0;
}