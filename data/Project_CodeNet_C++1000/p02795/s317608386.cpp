#include <bits/stdc++.h>
using namespace std;

inline int64_t ceiling_div(int64_t a, int64_t b){
  int64_t ans= ((a>=0 && b > 0) || (a<=0 && b < 0)) ? (abs(a)+abs(b)-1)/abs(b)
                                                    : -abs(a)/abs(b);
  return ans;
}

int main(){
  int H,W,N;
  cin >> H >> W >> N;

  int ans= ceiling_div(N, max(H,W));

  cout << ans << endl;
}