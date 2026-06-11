#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)

int main(){
  int N, K;
  cin >> N >> K;
  vector<int> p(N);
  rep(i,N){
    cin >> p.at(i);
  }
  int ans = 0;
  sort(p.begin(), p.end());
  rep(i,K){
    ans += p.at(i);
  }
  cout << ans;
  return 0;
}