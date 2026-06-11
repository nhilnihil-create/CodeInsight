#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
using namespace std;


int main ()
{

long long x;
cin >> x;
long long i,j;
bool flag=false;

for(i=1;i<10;i++)
{
	for(int j=1;j<10;j++)
	{
		if(i*j==x)
		{
			 flag=true;
			 break;
		}
	}
}

  if(flag)
  {
		cout << "Yes" << endl;
  }
  else
  {
		cout << "No"  << endl;
  }

	return 0;
}









