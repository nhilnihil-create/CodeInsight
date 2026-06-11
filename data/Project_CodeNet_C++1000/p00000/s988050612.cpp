#include<iostream>
#include<stdio.h>

using namespace std;

int main(){

	for( int i = 0; i <= 8; i++ )
	{
		for( int j = 0; j <= 8; j++ )
		{
			printf("%dx%d=%d\n", i+1, j+1, (i+1)*(j+1));
		}
	}

    return 0;
}
