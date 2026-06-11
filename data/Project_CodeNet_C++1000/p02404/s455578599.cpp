#include <iostream>
using namespace std;

int main()
{
	int h, w;
	while (cin >> h >> w, h || w)
	{
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++) cout << (i == 0 || i == h - 1 || j == 0 || j == w - 1 ? '#' : '.');
			cout << endl;
		}
		cout << endl;
	}
}
