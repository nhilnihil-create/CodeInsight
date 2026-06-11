#include <iostream>
#include <string>
using namespace std;

int main()
{
	int array[4] = { 0, 0, 0, 0 };

	string S, T;
	cin >> S >> T;

	int diff = 0;
	for (unsigned int i = 0; i < S.length(); i++)
	{
		if (S[i] != T[i])
		{
			diff++;
		}
	}

	cout << diff << endl;

	return 0;
}