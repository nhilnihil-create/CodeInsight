
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int N;
  cin >> N;
  long long all = 1;
  long long noNine = 1;
  long long neither = 1;
  for(int i = 0; i < N; i++){  
    all *= 10;
    all %= MOD;
    noNine *= 9;
    noNine %= MOD;
    neither *= 8;
    neither %= MOD;
    //cout << all << " " << noNine << " " << neither <<endl;
  }
  long long ans = all - noNine - noNine + neither;
  ans %= MOD;
  cout << (ans + MOD) % MOD <<endl;
}
