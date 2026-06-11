#include <iostream>
using namespace std;
int main()
{
	int a, b, k, x = 0;
	cin >> k >> a >> b;
	for (int i = a; i <= b; i++) {
		if (i%k == 0)
			x++;
	}
	if (x == 0)
		cout << "NG";
	else
		cout << "OK";
}