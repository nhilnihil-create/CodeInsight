#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll choose2(ll n){ //combination
  return n*(n-1)/2;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N),cnt(N);
  rep(i,N){
    cin >> A[i];
    A[i]--;
  }
  rep(i,N){
    cnt[A[i]]++;
  }
  ll tot = 0;
  rep(i,N){
    tot += choose2(cnt[i]);
  }
  rep(i,N){
    ll ans = tot;
    ans -= choose2(cnt[A[i]]);
    ans += choose2(cnt[A[i]]-1);
    cout << ans << endl;
  }
  return 0;
}
