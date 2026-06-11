#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  ll n;
  cin >> n;
  ll ans=n-1;
  rep(i,1000001){
    if(i!=0)if(n%i==0){
      ans=min(ans,i+n/i-2);
    }
  }
  cout << ans << endl;
  
}
