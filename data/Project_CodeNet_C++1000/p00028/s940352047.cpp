#include <iostream>

int answer[101];

int main(int argc, char const* argv[])
{
	int input;

	for( int i = 0;i < 101;i++ ) answer[i] = 0;

	while( std::cin >> input ){
		answer[input]++;
	}

	int max = 0;

	for( int i = 1;i < 101;i++ ){
		max = std::max( answer[i], max );
	}


	for( int i = 1;i < 101;i++ ){
		if( answer[i] == max ) std::cout << i << std::endl;
	}

	return 0;
}