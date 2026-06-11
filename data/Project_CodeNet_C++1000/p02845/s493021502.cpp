#include<bits/stdc++.h>
using namespace std;
int main () {
  int N;
  cin >> N;
  long long ans = 1;
  long long mod = 1e9 + 7;
  int cl[3];
  cl[0] = cl[1] = cl[2] = 0;
  for (int i = 0; i < N; i ++) {
    bool did = true;
    int a;
    cin >> a;
    int k = 0;
    for (int i_ = 0; i_ < 3; i_ ++) {
      if(cl[i_] == a) {
        k ++;
        if (did) {
          cl[i_] ++;
          did = false;
        }
      }
    }
    ans *= (long long)k;
    ans %= mod;
  }
  cout << ans << endl;
}

