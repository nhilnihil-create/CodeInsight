#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
using namespace std;


int main ()
{

int a,b;
cin >> a >>b;

if(a<b)
{
	 while(b-->0)
	 {
		  cout << a;
	 }
}
else
{
	  while(a-->0)
	  {
			cout << b;
	  }
}

	return 0;
}









