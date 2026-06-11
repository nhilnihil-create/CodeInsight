#include <iostream>
using namespace std;

int main()
{
	int w,h;
	int x,y;
	int r;
	int s;
	cin >> w >> h;
	cin >> x >> y;
	cin >> r;

	if(w >= x+r && h >= y+r && x+r>0 && y+r >0)
	{
		cout << "Yes" << endl;
 	}

 	else
 	{
 		cout << "No" << endl;
 	}

 	return 0;
}