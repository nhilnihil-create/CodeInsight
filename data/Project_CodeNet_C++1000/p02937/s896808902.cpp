#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string S, T; cin >> S >> T;
  ll N = S.size();
  ll M = T.size();
  vector<vector<ll> > alp(26, vector<ll>());
  REPLL(i, N){
    alp[S[i]-'a'].push_back(i);
  }

  ll now = -1, cnt = 1, ans = 0;
  REPLL(i, M){
    if(alp[T[i]-'a'].size() == 0){
      cout << -1 << endl;
      return 0;
    }
    auto itr = lower_bound(alp[T[i]-'a'].begin(), alp[T[i]-'a'].end(), now+1);
    if(itr == alp[T[i]-'a'].end()){
      now = alp[T[i]-'a'][0];
      ans = cnt*N + now;
      cnt++;
    }else{
      ll tmp = *itr;
      if(now < 0) now = 0;
      ans += tmp-now;
      now = tmp;
    }
  }
  ans++;
  cout << ans << endl;
}