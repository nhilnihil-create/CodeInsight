#include <bits/stdc++.h>
using namespace std;
int main(){
  int H,W,N,ans=0; cin >> H >> W >> N;
  int x = max(H,W);
  while(N>0) {
    N -= x;
    ans++;
  }
  cout << ans << endl;
}