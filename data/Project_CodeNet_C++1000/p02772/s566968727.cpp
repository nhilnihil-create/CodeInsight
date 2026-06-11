#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG




int main() {
  ll N;
  cin >> N;

  bool ans = true;
  //vector<ll> a(N);
  //vector<vector<int>> data(3, vector<int>(4));

  for(ll i=0; i <N; i++){
    ll tmp;
    cin >> tmp;
    if(tmp % 2 ==0){
      if(tmp % 3 ==0 || tmp % 5 ==0){
        continue;
      }else{
        cout << "DENIED" << endl;
        return 0;
      }
    }else{
      continue;
    }
  }
  cout << "APPROVED" << endl;
  return 0;
}
