#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
using Graph=vector<vector<ll>>;
int main(){
  int x,y;cin>>x>>y;
  int c=0;
  if(x==3)c+=100000;
  if(x==2)c+=200000;
  if(x==1)c+=300000;
  if(y==3)c+=100000;
  if(y==2)c+=200000;
  if(y==1)c+=300000;
  if(x==1&&y==1)c+=400000;
  cout<<c;
}