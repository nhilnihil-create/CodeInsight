#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

int main(){
  string s,t,u;
  int a,b;
  cin>>s>>t>>a>>b>>u;
  if(s==u) a--;
  else b--;
  cout<<a<<" "<<b<<endl;
}