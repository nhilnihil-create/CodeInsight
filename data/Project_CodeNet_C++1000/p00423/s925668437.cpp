#include <iostream>
using namespace std;
int main()
{
	int n, a, b, pa, pb, i;

	while (cin >> n && n)
	{
		for (i = 0, pa = pb = 0; i < n; i++)
		{
			cin >> a >> b;
			if (a > b)	pa += a + b;
			if (a == b)	pa += a, pb += b;
			if (a < b)	pb += a + b;
		}
		cout << pa << " " << pb << endl;
	}
	return 0;
}