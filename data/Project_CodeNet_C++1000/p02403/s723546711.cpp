#include<iostream>
int main()
{
	int a[300], b[300];
	int i = 1;
	int j = 1;
	int v = 0, t = 0;
	for ( int i = 1; i <= 300; i++ )
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
		for ( int i = 1; i <= j; i++ )
	{
		for ( int v = 0; v < a[i]; v++ )
	{
		for ( int t = 0; t <= b[i]; t++ )
	{
		if (  v < a[i] && t < b[i] )
	    {
			std::cout << '#';
		}
		else
		{
			std::cout << '\n';
		}
	}
	}
	if (i != j-1)
	{
		std::cout << '\n';
	}
		}
	return 0;
}
