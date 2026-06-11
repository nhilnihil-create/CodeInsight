#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()

void solve()
{
  ll n;
  cin>>n;
  ll k=n/500;
  n-=500*k;
  ll d=n/5;
  cout<<(k*1000)+(d*5)<<endl;
}

int main()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

        solve();

    return 0;
}

