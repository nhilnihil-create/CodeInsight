#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mk make_pair
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
  hs;
  ll a,b,ans=0,mm=1e9+7;
  cin>>a>>b;
  ll count=(a*(a+1))/2;
  //cout<<count<<endl;
  for(ll i=b-1;i<=a;i++)
  {
    ll count1=0,count2=0;
    count1=(i*(i+1))/2;
    count2=((a-i-1)*(a-i))/2;

    ans+=((count-count2)-count1+1);
  }
  cout<<ans%mm<<endl;
}
