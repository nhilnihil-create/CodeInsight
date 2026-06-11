#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<int(n);i++)
#define rep1(i,n) for(int i=1;i<int(n);i++)
#define all(a) (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using Pint = pair<int,int>;
const ll mod = 1e9+7;

int main(){
  ll a,b,k;
  cin>>a>>b>>k;

  if(a-k>0) cout<<a-k<<" "<<b<<endl;
  else if(b-(k-a)>0) cout<<0<<" "<<b-(k-a)<<endl;
  else cout<<0<<" "<<0<<endl;

  return 0;
}