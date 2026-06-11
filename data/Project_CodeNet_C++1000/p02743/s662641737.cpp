#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const double pi=acos(-1);





int main() 
{
  ll a,b,c; cin>>a>>b>>c;
  if(4*a*b<(c-a-b)*(c-a-b)&&c-a-b>=0) {cout<<"Yes"<<endl; return 0;}
  cout<<"No"<<endl;
  return 0;
}
