# include <iostream>
# include <math.h>

using namespace std;

int main()
{
	long long int X;
	long long int sum = 100;
	int years = 0;
	cin >> X;
	while (X > sum)
	{
		sum += sum / 100;
		years++;
	}

	cout << years;

	return 0; 
}