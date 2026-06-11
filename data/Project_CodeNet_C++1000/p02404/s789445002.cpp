#include<iostream>
int main()
{
	int a[300], b[300];
	int i = 0;
	int j = 0;
	int v = 0, t = 0;
	for ( int i = 0; i < 300; i++ )
	{
		std::cin >> a[i] >> b[i];
		if ( a[i] == 0 && b[i] == 0 )
		{
			break;
		}
		else
			{
				j++;
		    }
	}
		for ( int i = 0; i < j; i++ )
	{
		for ( int v = 0; v < a[i]; v++ )
	{
		for ( int t = 0; t <= b[i]; t++ )
	{
		if ( (v == 0 && t < b[i]) || ( v == (a[i]-1) && t < b[i]) || (t == 0 && v < a[i]) || ( t == (b[i]-1) && v < a[i]) )
	    {
			std::cout << '#';
		}
		else if ( t == b[i] )
		{
			std::cout << '\n';
		}
		else
			{
			std::cout << '.';
		    }
	}
	}
		std::cout << '\n';
		}
	return 0;
}
