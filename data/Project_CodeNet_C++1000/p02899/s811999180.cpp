#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,i,k,c=0;
    cin>>n;
    long long A[n];
    for(i=0;i<n;i++)
    {
      cin>>k;
      A[k]=i+1;
    }
    for(i=1;i<=n;i++)
     cout<<A[i]<<" ";
   
return 0;
}
