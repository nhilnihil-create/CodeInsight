#include <iostream>
#include <deque>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
int n;
int ans=0;
typedef vector<int> vi;
int main()
{
  while(1)
    {
      int n,m,p;
      cin >> n >> m >> p;
      if(!n) break;
      vi x(n);
      int totalbet=0;
      for(int i=0;i<n;i++)
	{
	  cin >> x[i];
	  totalbet+=x[i]*100;
	}
      totalbet-=(totalbet*p/100);
      if(x[m-1]>0) cout << totalbet/x[m-1] << endl;
      else cout << 0 << endl;
    }
  return 0;
}

