

#include<iostream>
using namespace std;


int main()
{
	int m[100], f[100], r[100];
	int i = 0;

	while (1)
	{
		cin >> m[i] >> f[i] >> r[i];

		if (m[i] == -1 && f[i] == -1 && r[i] == -1)
		{
			break;
		}
		
		if (m[i] == -1 || f[i] == -1)
		{
			cout << "F" << endl;
		}
		else if (m[i] + f[i] >= 80)
		{
			cout << "A" << endl;
		}
		else if (m[i] + f[i] >= 65 && m[i] + f[i] < 80)
		{
			cout << "B" << endl;
		}
		else if (m[i] + f[i] >= 50 && m[i] + f[i] < 65)
		{
			cout << "C" << endl;
		}
		else if (m[i] + f[i] >= 30 && m[i] + f[i] < 50)
		{
			if (r[i] >= 50)
			{
				cout << "C" << endl;
			}
			else
			{
				cout << "D" << endl;
			}
		}
		else
		{
			cout << "F" << endl;
		}
		i++;
	}
	return 0;
}