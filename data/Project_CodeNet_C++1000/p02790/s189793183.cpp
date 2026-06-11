#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

int main(){
  int a,b;
  cin>>a>>b;
  char c='0'+a ,d='0'+b;
  string x(a,d),y(b,c);
  if(x<y)cout<<x<<endl;
  else cout<<y<<endl;
}