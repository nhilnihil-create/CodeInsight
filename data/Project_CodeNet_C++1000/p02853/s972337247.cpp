#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;



int main(){
  int x,y;
  cin>>x>>y;
  int ans=0;
  if(x==1 && y==1) ans+=400000;
  ans+=100000*(x==3)+200000*(x==2)+300000*(x==1);
  ans+=100000*(y==3)+200000*(y==2)+300000*(y==1);

  cout<<ans<<endl;
  
}
