#include<iostream>
using std::cout;
using std::endl;
int main()
{
	for (int x = 1; x <= 9; x++)
	{
		for (int y = 1; y <= 9; y++)
		{
			cout << x <<"x"<< y <<"="<<x*y<<endl;
		}
	}
	return 0;
}