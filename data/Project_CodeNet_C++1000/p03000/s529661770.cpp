#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a,b;
  cin>>a>>b;
  ll x=0;
  ll y;
  for(ll i=1;x<=b;i++){
    ll c;
    cin>>c;
    x=x+c;
    y=i;
    if(y==a+1){
      break;
    }
  }
  cout<<y<<endl;
  return 0;
}
