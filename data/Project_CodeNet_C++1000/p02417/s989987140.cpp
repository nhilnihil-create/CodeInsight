#include <iostream>
#include <string>
using namespace std;

int main()
{
	char c;
	int nI[27] = { 0 };
	while (cin >> c)
	{
		int n = tolower(c);
		nI[n - '`'] += 1;
	}
	for (int i = 1; i < 27; i++)
	{
		printf("%c : %d\n", '`' + i, nI[i]);
	}
	//system("pause");
	return 0;
}