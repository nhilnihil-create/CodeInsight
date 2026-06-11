#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int main(){
  ll N;
  cin >> N;
  vl A(N);
  map<ll, ll> cnt;
  rep(i, N){
    cin >> A[i];
    cnt[A[i]]++;
  }

  stable_sort(A.begin(), A.end());

  vector<bool> dp(A[N - 1] + 1, true);

  ll ans = 0;
  vl done;

  rep(i, N){
    if(!dp[A[i]]) continue;
    
    if(cnt[A[i]] == 1) ans++;
    if((done.size() > 0) && (done[done.size() - 1] == A[i])) continue;

    done.push_back(A[i]);
    ll n = 2 * A[i];

    while(n <= A[N - 1]){
      dp[n] = false;
      n += A[i];
    }
  }
  
  cout << ans << "\n";
  
  return 0;
}
