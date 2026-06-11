#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
using namespace std;


int main ()
{

 double n,d;
 cin >> n >> d;
 double x,y;
 double count=0;
 while(n-->0)
 {
	 cin >> x >>y;
	 if((x*x+y*y)<=d*d)
	 {
		 count++;
	 }
 }

  cout << count << endl;

	return 0;
}









