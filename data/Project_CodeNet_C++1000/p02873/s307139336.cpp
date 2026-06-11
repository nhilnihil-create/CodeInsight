#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  string S;
  cin >> S;
  
  int N = S.size();
  vector<int> pos(N + 1, 0);
  
  for (int i = 0; i <= N - 1; i++){
    if (S.at(i) == '<'){
      pos.at(i + 1) = pos.at(i) + 1;
    }
  }
  
  for (int i = N - 1; i >= 0; i--){
    if (S.at(i) == '>'){
      pos.at(i) = max(pos.at(i + 1) + 1, pos.at(i));
    }
  }
  
  ll ans = 0;
  for (int i = 0; i <= N; i++){
    ans += pos.at(i);
  }
  
  cout << ans << endl;
}