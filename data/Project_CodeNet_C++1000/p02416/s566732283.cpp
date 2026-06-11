#include <iostream>
using namespace std;

int main()
{
	// Variable declaration
	char x[1001];
	int sum, i = 0;

	while (1)
	{
		// Input x
		cin >> x;

		// Check of value.
		if (x[0] == '0')
		{
			// End of Input.
			break;
		}

		while (x[i])
		{
			sum += x[i] - '0';
			i++;
		}

		// Output
		cout << sum << endl;

		// Initializ
		sum = 0;
		i = 0;
	}

	return 0;
}