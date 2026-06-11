#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
  ll n;
  cin>>n;
  ll a[n];
  for(ll i=0;i<n;i++)
  {
    cin>>a[i];
  }
  ll sum=0,cur=1000,i,j;
  for(i=0;i<n;)
  {
      for(j=i+1;j<n;j++)
      {
        //   cout<<i<<" "<<j<<endl;
          ll temp=a[j]-a[j-1];
            if(temp<0 )
            {
                
                sum+=(cur/a[i])*(a[j-1]-a[i]);
                cur=cur+(cur/a[i])*(a[j-1]-a[i]);
                // cout<<"sum="<<sum<<" "<<"cur="<<cur<<endl;
                break;     
            } 
            if( temp>=0 && j==n-1)
            {
                sum+=(cur/a[i])*(a[j]-a[i]);
                cur=cur+(cur/a[i])*(a[j]-a[i]);
                // cout<<"sum="<<sum<<" "<<"cur="<<cur<<endl;
                
            }
      }
      i=j;
  }
    
                         cout<<cur<<endl;
}