#include <iostream>
using namespace std;

void put_nchar(char c, int n)
{
	while (n-- > 0)
		cout << c;
}

int main()
{
	int H, W;
	while (true) {
		cin >> H >> W;
		if (H == 0 && W == 0) break;
		put_nchar('#', W);
		cout << endl;
		for (int i = 0; i < H - 2; i++)
		{
			put_nchar('#', 1);
			put_nchar('.', W - 2);
			put_nchar('#', 1);
			cout << endl;
		}
		put_nchar('#', W);
		cout << endl;
		cout << endl;
	}
	return 0;
}