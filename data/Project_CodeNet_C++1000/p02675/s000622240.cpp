#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int hon = N % 10;

	if (hon == 0 || hon == 1 || hon == 6 || hon == 8)
	{
		cout << "pon" << endl;
	}
	else if (hon == 3)
	{
		cout << "bon" << endl;
	}
	else
	{
		cout << "hon" << endl;
	}

	return 0;
}