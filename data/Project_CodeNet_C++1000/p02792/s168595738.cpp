#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

int main(){
  int n;
  const int max_n = 2 * 1e5;
  cin >> n;

  int cnt[10][10] = {};
  int length = 1;
  int f,l;

  for(int i = 1; i <= n; i++){
    if(i==10) length *= 10;
    if(i==1e2) length *= 10;
    if(i==1e3) length *= 10;
    if(i==1e4) length *= 10;
    if(i==1e5) length *= 10;

    cnt[i%10][(i/length)%10] ++;
    // cout << "i = " << i << ", ue = " << (i/length)%10 << ", sita = " << i%10 << endl;
  }
  // cout << "---" << endl;
  length = 1;
  long long ans = 0;
  for(int i = 1; i <= n; i++){
    if(i==10) length *= 10;
    if(i==1e2) length *= 10;
    if(i==1e3) length *= 10;
    if(i==1e4) length *= 10;
    if(i==1e5) length *= 10;

    ans += cnt[(i/length)%10][i%10];
    // if(cnt[(i/length)%10][i%10]>0) {
    //   cout << "i=" << i << ", cnt = " << cnt[(i/length)%10][i%10] << endl;
    // }
  }
  cout << ans << endl;

  return 0;
}