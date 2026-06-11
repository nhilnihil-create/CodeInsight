#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
using namespace std;


int main ()
{


int h,n;
cin >> h >> n;

int f,sum=0;

while(n-->0)
{

	 cin >> f;
	 sum+=f;

}

 if(sum-h>=0)
{
	 cout << "Yes" << endl;
}
else
{
	  cout << "No" << endl;
}
	return 0;
}









