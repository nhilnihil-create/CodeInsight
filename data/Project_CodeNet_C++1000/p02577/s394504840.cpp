#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back
int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  string n;
  cin>>n;
  ll sum=0;
  int a;
  for (ll i=0;i<n.size();i++)
  {
    a=n[i]-48;
    sum+=a;
  }
  if (sum%9==0)
  {
    cout<<"Yes";
  }
  else
    cout<<"No";
  return 0;
}