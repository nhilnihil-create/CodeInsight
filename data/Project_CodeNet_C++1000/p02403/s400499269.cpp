#include <iostream>
using namespace std;

int main()
{
	int h,w;
	while(1)
	{
		cin >> h >> w;
		int a[h][w];
		if(h==0 && w==0)
		{
			break;
		}
		for(int i=0; i<h; i++)
		{
			cout << "#";
			for(int j=0; j<w-1; j++)
			{
				cout << "#" ;
			}
			cout << endl;
		}

		cout << endl;
	}
}