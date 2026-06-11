#include <iostream>
#include <iomanip>

int main()
{
	int M, N;
    std::cin >> M >> N;
  	for(int i=0; i<N; i++)
    {
      	int A; 
		std::cin >> A;
        M -= A;
        if( M<0 ) { break; }
    }

	std::cout << (0 <= M ? M : -1) << std::endl;
	return 0; 
}