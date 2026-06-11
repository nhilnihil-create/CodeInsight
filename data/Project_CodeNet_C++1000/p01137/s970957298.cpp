#include<bits/stdc++.h>

using namespace std;

int main(){
  int e;

  while(1)
    {
      cin >> e;
      if(e == 0)break;
      int mini = INT_MAX;
      for(int z=0;z*z*z <= e;z++)
	{
	  for(int y=0;y*y<= e-(z*z*z);y++)
	    {
	      int x = e - y*y - z*z*z;
	      mini = min(mini,x+y+z);
	    }
	}
      cout << mini << endl;
    }
  return 0;
}
