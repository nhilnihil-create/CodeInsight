#include <iostream>

using namespace std;

int main()
{
	int K, X, start;
	cin >> K >> X;
	start = X - K + 1;
	for (int count = 0; count < 2 * K - 1; count++)
	{
		cout << start + count;
		if (count != 2 * K - 2)
		{
			cout << " ";
		}
	}
	cout << endl;
}