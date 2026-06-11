#include <iostream>
#define calc(x,y) (x*y)\

using namespace std;

int main(int argc, char **argv)
{
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++){
			cout << i << "x" << j << "=" << calc(i,j) << endl;
		}
	}
	
	return 0;
}