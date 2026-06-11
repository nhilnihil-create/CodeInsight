#include <iostream>
using namespace std;
#define rep(i, k) for(int i=0; i < (int)k; i++)
int main(){
  int L;
  cin>>L;
  int H[L],ans=0,best;
  const int inf=100000000;

  rep(i, L) cin >> H[i];
  best = inf;

  for(int i=0; i<100; i++){
    ans = 0;
    rep(j, L){
      ans += (H[j] - i) * (H[j] - i);
    }
    best = min(best, ans);
  }
  cout << best;

  return 0;
}
