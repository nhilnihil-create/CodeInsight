#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

const int MOD = 1000000007;
long long int n, k, a[3000];

int main(){
  cin >> n >> k;
  rep(i, n){
    cin >> a[i];
  }
  long long int b[n][2]; //0:subete 1:mae
  rep(i, n){b[i][1] = b[i][0] = 0;}
  rep(i, n){
    rep(j, n){
      if(a[j] < a[i]){
        b[i][0]++;
      }
      if(a[j] < a[i] && j > i){
        b[i][1]++;
      }
    }
  }
  rep(i, n){cerr << b[i][0] <<" "<< b[i][1]<<endl;}
  //-をなるべく使わない（modこわれる）
  long long int res = 0;
  rep(i, n){
    long long int sum1 = k * b[i][1];
    sum1 %= MOD;
    long long int sum2 = k * (k - 1);
    sum2 /= 2;
    sum2 %= MOD;
    sum2 *= b[i][0];
    res += sum1 + sum2;
    res %= MOD;
  }
  cout << res << endl;
  return 0;
}