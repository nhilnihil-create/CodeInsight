#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int E, x, y, z, min;
	
	while(cin >> E && E>0)
	{
		z=0; min = E;
		while(E-z*z*z>=0)
		{
			y=0;
			while(E-z*z*z-y*y>=0){
				x = E-z*z*z-y*y;
				if(min > x+y+z){
					min = x+y+z;
				}
				y++;
			}
			z++;
		}
		cout << min << endl;
	}
}
