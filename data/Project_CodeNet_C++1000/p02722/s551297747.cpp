#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

vector<ll> divisor(ll n){
  vector<ll> res;
  for(ll i = 1; i * i <= n; i++){
    if(n % i == 0){
      res.push_back(i);
      if(i != n / i) res.push_back(n / i);
    }
  }
  return res;
}

int main(){
  cout << setprecision(10);
  ll N; cin >> N;

  ll ans = 0;

  // KがNの約数のとき、割り切った後、N%K==1ならOK
  auto list = divisor(N);
  for(auto x: list){
    if(x==1) continue;
    ll n = N;
    while(n%x==0 && n >= 1){
      // cerr << "n: " << n << " x: " << x << endl;
      n/=x;
    }

    if(n%x==1) ans++;
  }

  // KがNの約数でないとき、N%K==1ならOK
  auto list2 = divisor(N-1);
  // 1以外
  ans += list2.size() - 1;

  cout << ans << endl;
   
}
