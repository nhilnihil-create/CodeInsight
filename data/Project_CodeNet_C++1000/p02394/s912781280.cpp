#include <iostream>
using namespace std;

int main()
{
	int W, H, x, y, r;
	cin >> W >> H >> x >> y >> r;
	
	if(x + r > W || x - r < 0)
	{
		if(y + r > H || y - r < 0)
		    cout << "No" << endl;
		else if(y + r <= H && y - r >= 0)
		    cout << "No" << endl;
		else
		    cout << "No" << endl;
	}
	else if(x + r <= W && x - r >= 0)
	{
		if(y + r > H || y - r < 0)
		    cout << "No" << endl;
		else if(y + r <= H && y - r >= 0)
		    cout << "Yes" << endl;
		else
		    cout << "No" << endl;
	}
	
	return 0;
}