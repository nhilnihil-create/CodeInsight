#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
          ll a,b,c=0;
          cin>>a;
          for(ll i=1;i<a+1;i++)
          {
                    ll s=0,d;
                    d=i;
                    while(d!=0)
                    {
                              d/=10;s++;
                    }
                    if(s&1)c++;
          }
          cout<<c<<endl;
}
