#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  ll n,suff=0;
  cin>>n;
  ll a[n];
  for(int i=0;i<n;i++){
        cin>>a[i];
        suff^=a[i];
  }
   ll ori=suff;
  ll xorr=0;
  for(int i=0;i<n;i++){
   a[i]=suff^a[i];
   cout<<a[i]<<" ";

  }
  cout<<endl;
}
