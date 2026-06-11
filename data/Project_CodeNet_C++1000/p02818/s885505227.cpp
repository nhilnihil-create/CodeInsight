#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll n,i,j,c=0,ans=0;
   ll a,b,k;
    cin>>a>>b>>k;
    c=b;
    b-=k-a;
    if(a<k)
     cout<<0<<" "<<max(0ll,b);
     else{
          cout<<a-k<<" "<<c;
     }
}
