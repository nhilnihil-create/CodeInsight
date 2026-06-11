#include <iostream>
using namespace std;

void put_nchar(char c, char d, int n)
{
	if (n % 2 == 0) {
		n /= 2;
		while (n-- > 0)
			cout << c << d;
	} else {
		cout << c;
		n--;
		n /= 2;
		while (n-- > 0)
			cout << d << c;
	}
}

int main()
{
	int H, W;
	while (true) {
		cin >> H >> W;
		if (H == 0 && W == 0) 
			break;
		for (int i = 0; i < H; i++) {
			if (i % 2 == 0) 
				put_nchar('#', '.', W);
			else 
				put_nchar('.', '#', W);
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}