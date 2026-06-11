#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// diverta2019 Programming Contest2 A
// 2020.05.26

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, K; cin >> N >> K;
  int ans;
  if(K != 1){
    ans = N-K;
  }else{
    ans = 0;
  }
  cout << ans << endl;
}