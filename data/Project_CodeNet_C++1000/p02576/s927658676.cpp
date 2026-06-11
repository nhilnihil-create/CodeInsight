#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, x, t;
  cin>>n;
  cin>>x;
  cin>>t;
  int output = 0;
  if( n%x > 0 ) output++;
  output = output+(n/x);
  output = output*t;
  cout<<output<<endl;
  return 0;
}