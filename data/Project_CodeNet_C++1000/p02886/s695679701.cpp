#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,n,i,j,s=0;
    cin>>n;
    long long A[n];
    for(i=0;i<n;i++)
      cin>>A[i];
    for(i=0;i<n;i++)
    {
      for(j=i+1;j<n;j++)
      {
         s+=A[i]*A[j];
      }
    }
  cout<<s<<endl;



return 0;
}
