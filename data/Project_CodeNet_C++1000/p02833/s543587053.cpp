#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  if(n%2==1){
    cout << 0;
    return 0;
  }
  ll ans=0;
  ll p=10;
  while(n>=p){
    ll q=n%p;
    ll cp=n-q;
    ans+=cp/p;
    p*=5;
  }
  cout << ans;
}
    
    