#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG



//桁数の計算
bool kaibun(string S){
  ll len = S.size();
  ll loop = len / 2 - 1;
  bool ans = true;

  for (ll i = 0; i <= loop ; i++){
    if(S.at(i) != S.at(len - 1 -i)){
      ans = false;
      break;
    }
  }
  return ans;
}



int main() {
  string S;
  cin >> S;

  ll N = S.size();
  string S1 = S.substr(0,(N-1)/2);
  string S2 = S.substr((N+3)/2 - 1);
  


  if (kaibun(S) && kaibun (S1) && kaibun (S2)) {
    cout << "Yes" << endl;
    return 0; 
  }
  cout << "No" << endl;
  return 0;
}
