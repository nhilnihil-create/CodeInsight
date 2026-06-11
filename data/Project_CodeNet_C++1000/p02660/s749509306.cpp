#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
#define rep(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

int main(){
  ll N; cin >> N;
  if(N==1){
    cout << 0 << endl;
    return 0;
  }
  ll n = N;
  ll ans = 0;
  for(ll i=2;i*i<=N;i++){
    ll x = i;
    while(n%x==0){
      ans++;
      n /= x;
      x *= i; 
    }
    while(n%i==0){
      n /= i;
    }
  }
  if(n != 1) ans++;
  cout << ans << endl;
}
