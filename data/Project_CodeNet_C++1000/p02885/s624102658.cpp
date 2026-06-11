#include <iostream>

using namespace std;

int main(void)
{
	int A, B, C;

	cin >> A >> B;

	C = A - 2*B;
	if (C > 0)
	{
		cout << C << endl;
		return 0;
	}
	else
	{
		cout << 0 << endl;
		return 0;
	}

}