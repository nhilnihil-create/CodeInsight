#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()

void solve()
{
  ll a,b;
  cin>>a>>b;
  ll k=__gcd(a,b);
   cout<<(a*b)/k<<endl;
}

int main()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

        solve();

    return 0;
}

