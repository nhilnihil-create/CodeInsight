#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

const ll MOD = (ll)pow(10,9)+7;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }
  ll T1 = 0;
  rep(i,n){
    for(int j=i+1;j<n;j++){
      if(a[i]>a[j]) T1 ++;
    }
  }
  ll T2 = 0;
  rep(i,n){
    rep(j,n){
      if(a[i]>a[j]) T2 ++;
    }
  }
  ll ans = 0;
  ans += T1*k;
  ans %= MOD;
  if(k%2 == 0) ans += (T2*k/2)%MOD*(k-1);
  if(k%2 == 1) ans += (T2*(k-1)/2)%MOD*k;
  ans %= MOD;
  cout << ans << endl;
}