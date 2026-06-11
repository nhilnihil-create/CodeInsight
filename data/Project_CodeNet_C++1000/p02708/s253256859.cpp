#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG
#define M 1000000007




int main() {
  ll N, K, ans;
  cin >> N >> K;

  ans = 0;

  for (ll i = K; i<=N+1; i++){
    ll min, max;
    min = i*(i+1)/2;
    max = i*((N+1) + (N+1-i + 1))/2;
    ans += (max - min +1);
    //ans %= M;
  }
   
  cout << ans % M << endl;

  return 0;
}
