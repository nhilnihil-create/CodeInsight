#include<iostream>

bool f[30];

int main()
{
	for( int i = 0; i < 28; i++ ){
		int x;
		std::cin >> x;
		f[x-1] = true;
	}
	
	for( int i = 0; i < 30; i++ ){
	 	if( !f[i] ){
		 	std::cout << i + 1 << std::endl;
		}
	}

 	return 0;
}