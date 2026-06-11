#include<bits/stdc++.h>

using namespace std;

int main()
{
 int n,x,t;
 
 cin>>n>>x>>t;
  int i=1;
  while(1){
  if(x*i>=n)
    break;
    i++;
    }
  cout<<t*i;
  return 0;
  
}
