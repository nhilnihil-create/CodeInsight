#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;

  int N, M;
  string S;
  cin >> N >> M;
  cin >> S;
  vector<int> ans;
  int i = N;
  while(i > 0){
    if(i <= M){
      ans.push_back(i);
      break;
    }
    for(int j = M; j > 0; j--){
      if(S[i-j] == '0'){
        ans.push_back(j);
        i -= j;
        break;
      }
      if(j == 1){
        cout << -1 <<endl;
        return 0;
      }
    }
  }
  for(int i = 0; i < ans.size(); i++){
    cout << ans.at(ans.size() - i - 1) << " ";
  }
}
