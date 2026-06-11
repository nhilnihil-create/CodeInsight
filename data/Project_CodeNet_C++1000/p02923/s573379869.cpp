#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long N;
  cin >> N;
  vector<long long> H(N);
  for(long long i = 0; i < N; ++i) {
    cin >> H[i];
  }
  reverse(H.begin(), H.end());

  long long ans = 0, max_num = 0;
  long long now_height = H[0], now_num = 0;


  for(long long i = 1; i < N; ++i) {
    if(now_height <= H[i]) {
      max_num++;
      now_height = H[i];
    }
    else {
      max_num = 0;
      now_height = H[i];
    }
    ans = max(max_num, ans);
  }

  cout << ans << endl;
  return 0;
}
