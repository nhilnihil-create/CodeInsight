#include <iostream>
#include <string>

using namespace std;

int main()
{
	int		H, W;

	for (;;)
	{
		cin >> H >> W;

		if ((H == 0) && (W == 0))
			break;

		string		str("#");

		for (int i = 1; i < W; i++)
			str += "#";
		str += "\n";

		for (int i = 0; i < H; i++)
		{
			cout << str;
		}
		cout << "\n";
	}

	return 0;
}