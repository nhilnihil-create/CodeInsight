#include "bits/stdc++.h"
using namespace std;

int main()
{
  int64_t n,blue,red,x,y;
  cin>>n>>blue>>red;
  x=n/(blue+red)*blue;
  y=n%(blue+red);
  if(y>=blue)
    y=blue;
  cout<<x+y<<endl;
}