#include <bits/stdc++.h>
using namespace std;
int main(){
  int H,W,N; cin >> H >> W >> N;
  int M = max(H,W);
  int ans = N/M;
  if(N%M!=0) ans++;
  cout << ans << endl;
}