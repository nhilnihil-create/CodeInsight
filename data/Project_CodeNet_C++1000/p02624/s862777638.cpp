#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define rep1(i, n) for(ll i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int main(){
  int k;
  cin >> k;
  ll ans = 0;
  rep1(j,k){
    ll a = j;
    ll d = j;
    ll n = k/j;
    ll sum = n*(2*a+(n-1)*d)/2;
    ans += sum;
  }
  cout << ans << endl;
}
