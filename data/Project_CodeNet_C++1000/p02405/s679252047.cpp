#include<iostream>
using namespace std;
int main()
{
	int H, W, i, k, j;
	while(1)
	{	
		cin >> H >> W;
		if ( H == 0 && W == 0 )break;
		else
		{
			for ( i = 0; i < H; i++)
				{
					if ( i % 2 == 1 )
						{
							for ( k = 0; k < W; k++)
							{
								j = k % 2;
								if ( j == 1 )cout << "#";
								else if ( j == 0 )cout << ".";
							}
							cout << endl;
						}
					else if ( i % 2 == 0 )	
						{
							for ( k = 0; k < W; k++)
							{
								j = k % 2;
								if ( j == 1 )cout << ".";
								else if ( j % 2 == 0 )cout << "#";
							}
							cout << endl;
						}
				}
		}
	cout << endl;
	}
return 0; 
}