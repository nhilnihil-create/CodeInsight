#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using d = double;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int l=0;
  if(a==b)++l;
  if(b==c)++l;
  if(c==a)++l;
  if(l==1)return cout<<"Yes"<<endl,0;
  cout<<"No"<<endl;
  return 0;
}