#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,k,c=0,i;
  cin>>n>>k;
  long A[n];
  for(i=1;i<=n;i++)
  {
    cin>>A[i];
    if(A[i]>=k) c++;
  }
  cout<<c<<endl;
}
