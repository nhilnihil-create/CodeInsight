#include<iostream>
using namespace std;

int main(){
	unsigned a, b;
	for ( a = 1; a  <= 9; a++ )
	{
		for ( b = 1; b <= 9; b++ )
		{
			cout  << a << 'x' << b << '=' << a * b << endl;
		}
	}
	return 0;
}