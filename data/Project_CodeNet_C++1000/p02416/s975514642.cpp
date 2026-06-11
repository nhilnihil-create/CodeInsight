#include <iostream>
using namespace std;

int main ()
{
	char number[1000];
	while (1)
	{
		cin >> number;
		if (number[0]==48)
			break;
		int sum=0;
		int i=0;
		while (number[i])
		{
			sum += number[i] - 48;
			i++;
			}	
		cout << sum << endl;
	}
	return 0;
}