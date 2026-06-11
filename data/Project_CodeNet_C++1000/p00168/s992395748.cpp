#include <iostream> 
using namespace std;


int main()
{
	while (true)
	{
		int ary[40];
		int n;
		cin >> n;
		if (n == 0) return 0;

		ary[0] = 1;
		ary[1] = 1;
		ary[2] = 2;
		for (int i = 3; i < n + 1; i++)
		{
			ary[i] = ary[i - 1] + ary[i - 2] + ary[i - 3];
		}

		cout << (ary[n] / 3650) + 1 << endl;
	}

	return 0;
}