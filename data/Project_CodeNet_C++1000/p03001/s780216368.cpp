#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;





int main() 
{
  ll H,W; cin>>W>>H;
  ll x,y; cin>>x>>y;
  cout<<(double)(H*W)/2<<" ";
  if((W%2==0&&x==W/2)&&(H%2==0&&y==H/2)) {cout<<1<<endl; return 0;}
  cout<<0<<endl;
  return 0;
}
