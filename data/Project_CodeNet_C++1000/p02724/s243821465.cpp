#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  ll a;
  cin>>a;
  ll ans = 0;
  ans = (a/500)*1000 + ((a%500)/5)*5;
  cout<<ans<<endl;

return 0;
}

