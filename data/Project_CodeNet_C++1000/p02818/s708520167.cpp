#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

int main()
{
    ll n,m,k;
    cin>>n>>m>>k;

 if (k<=n)
  cout<<n-k<<" "<<m<<endl;

  else if(k<=n+m)
    cout<<0<<" "<<n+m-k<<endl;

  else
    cout<<0<<" "<<0<<endl;

  exit(0);



}
