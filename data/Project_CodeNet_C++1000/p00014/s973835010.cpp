#include <iostream>

using namespace std;

int main()
{
	int d;
	while(cin >> d)
	{
		int integral = 0;
		for(int i = 0; i < 600 / d; i++)
		{
			int x =  i * d;
			int y = x * x;
			integral += y * d;
		}
	
		cout << integral << endl;
	}
	return 0;
}