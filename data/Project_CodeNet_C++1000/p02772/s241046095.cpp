
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
          ll n,c=0,i;
          set<ll>s;
           cin>>n;
          ll a[n+1];
          vector<ll>v;
         
          for(ll i=0;i<n;i++)
          {
                    cin>>a[i];
                    if(a[i]%2==0)
                          {
                             v.push_back(a[i]);
                          }
          }
          for(i=0;i<v.size();i++)
          {
                    if(v[i]%3!=0 && v[i]%5!=0)
                              c=1;
          }
          if(c==1)
                    cout<<"DENIED";
          else cout<<"APPROVED";
          
}
