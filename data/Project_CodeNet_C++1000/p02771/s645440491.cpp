#include <bits/stdc++.h>

int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;
	if ( ((a==b) && (b==c) && (c==a)) ||
		 ((a!=b) && (b!=c) && (c!=a)) )
	{
		std::cout << "No" << std::endl;
	}
	else
	{
		std::cout << "Yes" << std::endl;
	}
	return 0;
}
