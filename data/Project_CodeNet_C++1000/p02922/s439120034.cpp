//power sockets
#include<iostream>
using namespace std;
int main()
{
	int a, b, i;
	cin >> a >> b;
	for (i = 0; i < 21; i++)
	{
		if ((a - 1)*i + 1 >= b)
		{
			cout << i << " " << endl;
			break;
		}
	}
	return 0;
}
