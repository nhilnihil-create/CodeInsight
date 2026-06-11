//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>

using namespace std;

const int nmax = 1e9 + 7;
const long long INF = 1e18;
const double PI = 2 * asin(1);
typedef long long ll;

ll AN(ll A, ll N, ll mod){
  if (N == 0){
    return 1;
  }else{
    if (N % 2 == 0){
      return AN(A * A % mod, N / 2, mod);
    }else{
      return A * AN(A * A % mod, N / 2, mod) % mod;
    }
  }
}

int main(){
  int N; cin >> N;
  
  ll ans = 1;
  vector <ll> D(N);
  for (int i = 0; i < N; i++){
    cin >> D[i];
  }
  if (D[0] != 0) ans = 0;

  sort(D.begin(), D.end());
  vector <ll> cnt(D[N - 1] + 1);
  for (int i = 0; i < N; i++){
    cnt[D[i]]++;
  }

  if (cnt[0] != 1) ans = 0;
  
  for (int i = 1; i < D[N - 1] + 1; i++){
    ans *= AN(cnt[i - 1], cnt[i], 998244353);
    ans %= 998244353;
  }
  cout << ans << endl;
  
  return 0;
}
