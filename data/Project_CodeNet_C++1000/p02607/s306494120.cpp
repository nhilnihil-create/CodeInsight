#include<iostream>
#include<bits/stdc++.h>
#define ll long long int

using namespace std;
int main()
{
  ll n;
  cin >> n;
  ll i,a[n+1];
  ll cnt =0;
  for(i=1;i<=n;i++)
  {
    cin >> a[i];
    if(i%2==1&&a[i]%2==1)
    {
      cnt++;
    }
  }
  cout << cnt << endl;
}