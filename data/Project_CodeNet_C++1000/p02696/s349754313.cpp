#include "bits/stdc++.h"
using namespace std;

int main()
{
  int64_t a,b,n;
  cin>>a>>b>>n;
  if(n>=b-1)
    cout<<a*(b-1)/b<<endl;
  else
    cout<<a*n/b<<endl;
}