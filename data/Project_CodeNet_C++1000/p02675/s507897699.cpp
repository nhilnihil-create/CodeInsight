#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if (n % 10 == 0 || n % 10 == 1 || n % 10 == 6 || n % 10 == 8)
		cout << "pon";
	else if (n % 10 == 3)
		cout << "bon";
	else
		cout << "hon";

}