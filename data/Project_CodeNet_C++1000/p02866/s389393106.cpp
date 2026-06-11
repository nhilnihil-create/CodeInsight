#include<iostream>
#include<vector>
using namespace std;
const long long mod = 998244353;

int main(){
  int N;
  cin >> N;

  vector<int> D_cnt(N);
  int d_max = 0;
  for(int i = 0; i < N; i++){
    int d;
    cin >> d;
    if(d >= N || (i == 0 && d != 0) || (i != 0 && d == 0)){
      cout << 0 << endl;
      return 0;
    }
    D_cnt[d]++;
    d_max = max(d_max, d);
  }

  long long ans = 1;
  for(int i = 1; i <= d_max; i++){
    for(int j = 0; j < D_cnt[i]; j++){
      ans *= D_cnt[i - 1];
      ans %= mod;
    }
  }
  cout << ans << endl;
}

