  #include<bits/stdc++.h>
  #define ll long long
  const ll mod=1e9+7;
  using namespace std;
  ll power(ll a,ll c)
{

   ll ans=1,b=c;
  if(b==0)
  cout<< 1<<endl;
  while(b!=1)
{
    if(b%2==1)
    ans=ans*a%mod;

    a=a*a%mod;
   b=b/2;

  }
  cout<<ans*a%mod<<endl;



  }

  int main()
  {
    ll a,b;
    cin>>a>>b;
    power(a,b);

return 0;

  }

