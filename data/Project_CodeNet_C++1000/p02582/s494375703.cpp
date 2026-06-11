# include <iostream>
# include <string.h>

using namespace std;

int main()
{
	string day;

	cin >> day;

	int count= 0;

	for (int  i = 0; i < 3; i++)
	{
		if (day[i] == 'R')
		{
			count++;
		}
	}
	if (count != 2)
		cout << count;
	else if (count == 2)
	{
		if (day[1] == 'S')
			cout << 1;
		else
			cout << count;
	}

	return 0;
}