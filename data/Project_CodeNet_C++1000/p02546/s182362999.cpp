#include<bits/stdc++.h>
using namespace std;

int main()
{
 	 string x;
  	cin >> x;
  	int n;
  	n = x.length();
    if (x[n-1] == 's')
    {
      x[n] = 'e';
      x[n+1] = 's';
    }
    else
    {
      x[n] = 's';
    }
  int y;
  y = 0;
  while ( x[y]!=0)
  {
   	cout << x[y];
    y++;
  }
}