#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll MOD = 1000000007;
ll n, k, a[2020];
ll invall[2020], invback[2020];

int main(){
  cin >> n >> k;
  rep(i, n) cin >> a[i];
  rep(i, n){
    rep(j, n){
      if(a[j] >= a[i]) continue;
      invall[i]++;
      if(j > i)
        invback[i]++;
    }
  }
  //rep(i, n) cerr << invall[i] << " "; cerr << endl;
  //rep(i, n) cerr << invback[i] << " "; cerr << endl;
  
  ll res = 0;
  rep(i, n){
    res += (invback[i] * k) % MOD;
    res %= MOD;
  }
  rep(i, n){
    ll tmp = invall[i];
    tmp *= ((k * (k - 1)) / 2) % MOD;
    res += tmp;
    res %= MOD;
  }
  
  cout << res << endl;
}