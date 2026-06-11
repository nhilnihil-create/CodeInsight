#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll>pll;
const int N=1e6;
ll v[N+10];
ll pos[N];
int main()
{
    ll n;

    cin>>n;

    vector<pll>v;

   for(ll i=0;i<n;i++)
    {
        ll a,b;

        cin>>a>>b;

        v.push_back({b,a});

    }
    sort(v.begin(),v.end());

    ll sum=0,flag=0;

   for(auto i:v)
   {
      sum+=i.second;

      if(sum>i.first)
      {
          flag=1;
          break;
      }
   }

   if(flag==1)
   {
       cout<<"No"<<endl;
   }
   else cout<<"Yes"<<endl;




}



