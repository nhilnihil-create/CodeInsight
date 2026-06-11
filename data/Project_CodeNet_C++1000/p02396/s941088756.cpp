#include<iostream>

int i = 1 , x = 1 ;

int main()
{
	for(;x != 0 ; i++)
	{
		std::cin >> x ;
		if(x != 0)
		{
			std::cout << "Case " << i << ": " << x << std::endl ;
		}
	}
}