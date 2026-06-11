#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC159 D - Banned K
// 2020.06.27
// n(n-1)/2

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  vector<int> A(N);
  map<int, ll> mp;
  REP(i, N){
    cin >> A[i];
    mp[A[i]]++;
  }
  ll ans = 0;
  for(auto i : mp){
    ans += i.second*(i.second-1)/2;
  }
  for(auto i : A){
    if(mp[i] >= 2){
      ll res = ans;
      res -= mp[i]*(mp[i]-1)/2;
      res += (mp[i]-1)*(mp[i]-2)/2;
      cout << res << endl;
    }else{
      cout << ans << endl;
    }
  }
}