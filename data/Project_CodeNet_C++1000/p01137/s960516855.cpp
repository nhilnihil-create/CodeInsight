#include <iostream>
using namespace std;

int main()
{
  int e;
  while(cin >> e && e>0)
    {
      int m=e;
      for(int z=0; z*z*z<=e; z++)
	for(int y=0; y*y<=e-z*z*z; y++)
	  {
	  int x = e-z*z*z-y*y;
	  m = min(m, x+y+z);
	  }
      cout << m << endl;
    }
}

