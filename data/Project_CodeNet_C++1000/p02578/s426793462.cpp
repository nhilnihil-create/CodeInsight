#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back
int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ll n;
  cin>>n;
  vector <ll> a(n);
  ll H=0,h=0;
  for (ll i=0;i<n;i++)
  {
    cin>>a[i];
    if (H>a[i])
    {
      h+=H-a[i];
    }
    H=max(H,a[i]);
  }
  cout<<h;
  return 0;
}