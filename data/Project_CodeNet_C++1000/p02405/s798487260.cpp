#include <iostream>

using namespace std;

void printChessboard(const int row_number, const int width)
{
	int n = row_number % 2;
	for(int i = 0; i < width; i++){
		if(i % 2 == n){ cout << "#"; }
		else          { cout << "."; }
	}
	cout << endl;
}

int main()
{
	int h = 0, w = 0;
	while(true)
	{
		cin >> h >> w;
		if(h == 0 && w == 0){ break; }
		for(int y = 0; y < h; y++)
		{
			printChessboard(y, w);
		}
		cout << endl;
	}

	return 0;
}