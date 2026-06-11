#include <iostream>
#include <cmath>

using namespace std;

bool Function(int x)
{
	for (float i = 1; i <= 9; ++i)
	{
		for (float j = 1; j <= 9; ++j)
		{
			if ((x / i) / j == 1.0f) return true;
		}
	}
	return false;
}

int main()
{
	int N;
	cin >> N;

	if (Function(N)) cout << "Yes";
	else cout << "No";

	return 0;
}
