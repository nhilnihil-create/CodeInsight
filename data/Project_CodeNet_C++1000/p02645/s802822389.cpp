#include <iostream>

using namespace std;

int main()
{
	char S[20];
	char P[2];
	int i = 0;

	cin >> S;
	while(i < 3)
	{
		P[i] = S[i];
		i++;
	}
	cout << P << endl;
	return 0;
}