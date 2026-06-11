#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll x,k,d;
  cin >> x>>k>>d;
  ll ans;
  if(x<0){
    x=-x;
  }
  ll p=x/d;
  if(p>k){
    cout << x-k*d;
    return 0;
  }
  k=k-p;
  ans=x%d;
  if(k%2==1){
    cout <<abs(ans-d);
    return 0;
  }
  cout << ans;
}

