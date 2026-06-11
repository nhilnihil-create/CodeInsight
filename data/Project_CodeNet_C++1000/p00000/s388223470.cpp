#include<iostream>
using namespace std;

int main()
{
	const int kMax = 9;
	for(int i = 1; i <= kMax; i++)
	{
		for(int j = 1; j <= kMax; j++)
		{
			cout << i << "x" << j << "=" << i * j << endl;
		}
	}
    return 0;
}