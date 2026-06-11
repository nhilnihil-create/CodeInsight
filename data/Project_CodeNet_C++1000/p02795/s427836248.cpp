#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int h, w, n;

	cin >> h;
	cin >> w;
	cin >> n;

	int a;
	if (w > h)
	{
		a = n / w;
		if (n % w != 0) a++;
	}
	else
	{
		a = n / h;
		if (n % h != 0) a++;
	}
	cout << a << endl;
	return 0;
}