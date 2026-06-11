#include<bits/stdc++.h>

using namespace std;

int main()
{
  int n,k;
  cin>>n>>k;
  int maxn=n-k+1;
  if(k==1)
  {
      cout<<"0"<<endl;
      return 0;
  }
  cout<<maxn-1<<endl;
}
