#include<math.h>
#include<iostream>

using namespace std;

int main()
{
	int x1,y1,x2,y2;
	double d,x,y;

	cin >> x1 >> y1 >> x2 >> y2;

	x = (x2-x1)*(x2-x1);

	y = (y2-y1)*(y2-y1);


	d = sqrt((x+y));

	cout << d << endl ;

	return 0;
}