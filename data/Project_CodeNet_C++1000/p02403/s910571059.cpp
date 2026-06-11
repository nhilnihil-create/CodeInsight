#include <iostream>

using namespace std;

int main()
{
	int h = 0, w = 0;
	while(true)
	{
		cin >> h >> w;
		if(h == 0 && w == 0){ break; }
		for(int y = 0; y < h; y++)
		{
			for(int x = 0; x < w; x++)
			{
				cout << '#';
			}
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}