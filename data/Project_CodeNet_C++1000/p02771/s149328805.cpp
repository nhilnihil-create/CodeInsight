#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

int main(){
  int a,b,c;
  cin>>a>>b>>c;
  bool ans=1;
  if(a==b && b==c && c==a) ans=0;
  if(a!=b && b!=c && c!=a) ans=0;
  if(ans) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}