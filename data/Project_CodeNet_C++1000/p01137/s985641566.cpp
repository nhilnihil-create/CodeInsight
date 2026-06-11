#include<iostream>
using namespace std;

int Count = 0; //    global

int solve(int E) {
  int x,ans=1000110;
  Count=0;
  for (int z=0; z*z*z<=E; ++z)
    for (int y=0; y*y<=(E-z*z*z); ++y)
      {
	Count++;
	x=(int)E-y*y-z*z*z;
	if(x+y*y+z*z*z==E)
	  {
	    if(ans>x+y+z)
	      ans=x+y+z;
	  }
      }
  return ans;
}

int main() {
  int E;
  while (cin >> E && E>0) {
    cout << solve(E) << endl;
    //cout<<"count="<<Count<<endl;
  }
}