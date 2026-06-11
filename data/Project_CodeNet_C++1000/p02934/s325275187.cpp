#include "bits/stdc++.h"
using namespace std;
int main()
{
  long t,x;
  cin>>t;
  float sum=0.0;
  for(int i=1;i<=t;i++)
  {
    cin>>x;
    sum+=1.0/x;
  }
  cout<<fixed<<setprecision(10)<<1.0/sum<<endl;
}
