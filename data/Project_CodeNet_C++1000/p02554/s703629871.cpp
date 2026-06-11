#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define K 1000000007

ll pown(ll x, ll y){
  ll res=1;
  rep(i,y){
    res= res * x % K;
  }
  return res;
}



int main() {
  ll N;
  cin >> N;
  //vector<ll> a(N);
  //vector<vector<int>> data(3, vector<int>(4));

  ll ans;
  ans = pown(10, N) - pown(9, N) - pown(9, N) + pown(8, N);
  ans = ans % K;
  ans = (ans + K)% K;
  cout << ans << endl;

  return 0;
}
