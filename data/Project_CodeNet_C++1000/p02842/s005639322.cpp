#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	int N;
	std::cin >> N;

	bool isFinded = false;
	for(int i=N; i>=0; i--)
	{
		int now = i * 1.08;
		if( N == now )
		{
			isFinded = true;
			std::cout << i << std::endl;
			break;
		}
	}

	if( isFinded == false )
	{
		std::cout << ":(" << std::endl;
	}

	return 0;
}
