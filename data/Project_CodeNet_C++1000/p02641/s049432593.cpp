#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)

int main(){
  int X, N;
  cin >> X >> N;
  vector<int> p(N);
  vector<bool> exist(110,false);
  rep(i,N){
    cin >> p.at(i);
    exist.at(p.at(i)) = true;
  }
  int ans;
  int tmp = 200;
  for(int i=0; i<=101; i++){
    if(tmp>abs(X-i)&&!exist.at(i)){
      ans = i;
      tmp = abs(X-i);
    }
  }
  cout << ans;
  return 0;
}