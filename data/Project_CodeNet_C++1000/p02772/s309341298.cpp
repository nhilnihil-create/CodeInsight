#include <bits/stdc++.h>

int main()
{
	int N;
	std::cin >> N;
	std::vector<int> A(N);
	for(int i=0; i<N; i++)
	{
		std::cin >> A[i];
	}

	bool isOk = true;
	for(int i=0; i<N; i++)
	{
		if( A[i] % 2  == 0 )
		{
			if( A[i] % 3 != 0 ) 
			{
				if( A[i] % 5 != 0 )
				{
					isOk = false;
					break;
				}
			}
		}
	}

	if(isOk)
	{
		std::cout << "APPROVED" << std::endl;
	}
	else
	{
		std::cout << "DENIED" << std::endl;
	}

	return 0;
}
