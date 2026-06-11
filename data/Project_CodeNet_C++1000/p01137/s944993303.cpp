#include<iostream>
#include<math.h>
//#include<limits.h>
using namespace std;
int solve(int E)
{
  int ans =999999;
  for (int z=0; z*z*z<=E; z++)
    for (int y=0; y*y<=E; y++)
      {
	//cout<<"z="<<z<<" y="<<y<<endl;
	int x=E-z*z*z-y*y;
	//cout<<"x="<<x<<endl;
	//cout<<"x+y*y+z*z*z="<<x+y*y+z*z*z<<endl;
	if ((x+y*y+z*z*z == E)&&(x>=0))
	{

	  if((x+y+z)<ans)
	  {
	    ans=x+y+z;
	    //cout<<"ans="<<ans<<endl;
	  }
	}
      }
  return ans;
}
int main()
{
  int E;
  while (cin >> E && E>0)
  {
    cout << solve(E) << endl;
  }
}