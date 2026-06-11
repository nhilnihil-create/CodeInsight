#include<bits/stdc++.h>
using namespace std;
int main()
{
  int x,n;
  cin>>x>>n;
  int z,a[102]={0};
  for(int i=0;i<n;i++) { cin>>z; a[z]++; }
  bool good = false;
  int i=x,j=x;
  while(!good)
  {
    if(a[i]==0) { good = true; cout<<i<<"\n"; }
    else if(a[j]==0) { good = true; cout<<j<<"\n"; }
    i--;
    j++;
  }
  return 0;
}
