#include<bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,x,t;
  cin>>n>>x>>t;
  int k = (n+x-1)/x;
  cout<<k*t<<"\n";
  return 0;
}