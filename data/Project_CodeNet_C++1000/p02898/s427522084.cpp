#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
using namespace std;


int main ()
{

int n,k,count=0,a;
cin >> n >> k;


while(n-->0)
{
	cin >> a;
	if(a>=k)
	{
		  count++;
	}
}

cout << count << endl;
	return 0;
}









