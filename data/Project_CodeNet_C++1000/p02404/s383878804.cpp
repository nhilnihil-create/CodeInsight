#include <iostream>
using namespace std;

void frame1(const int width)
{
	for(int i = 0; i < width; i++){
		cout << "#";
	}
	cout << endl;
}

void frame2(const int width)
{
	for(int i = 0; i < width; i++){
		if(i == 0 || i == width - 1)
		{
			cout << "#";
		}
		else
		{
			cout << "."; 
		}
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
			if(y == 0 || y == h - 1){ frame1(w); }
			else                    { frame2(w); } 
		}
		cout << endl;
	}

	return 0;
}