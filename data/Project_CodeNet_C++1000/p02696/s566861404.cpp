#include "bits/stdc++.h"
using namespace std;

int main()
{
  int64_t a,b,n,m;
  cin>>a>>b>>n;
  m=min(b-1,n);
  cout<<a*m/b;
}