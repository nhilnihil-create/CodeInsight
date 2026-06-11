#include <bits/stdc++.h>
using namespace std;
int main() 
{
    long int n,k,q;
      cin>>n>>k>>q;
      long int i,j,a[q],b[n]; 
      for(i=0;i<q;i++)
      {
          cin>>a[i];
          
      }
      for(i=0;i<n;i++)
      {
          b[i]=k;
      }
      for(i=0;i<q;i++)
      {
          b[a[i]-1]+=1;
          
      }
      for(i=0;i<n;i++)
      {
          b[i]-=q;
          //cout<<b[i]<<endl;
      }
      for(i=0;i<n;i++)
      {
          if(b[i]<=0)
          {
              cout<<"No"<<endl;
          }
          else
          {
              cout<<"Yes"<<endl;
          }
      }
}
