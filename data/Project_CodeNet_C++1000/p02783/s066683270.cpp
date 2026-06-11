#include <iostream>
using namespace std;


int main () {

int h,a;
cin >> h >> a;
int count=0;

while(h>0)
{
	h=h-a;
	count++;
}

cout << count;

	return 0;
}









