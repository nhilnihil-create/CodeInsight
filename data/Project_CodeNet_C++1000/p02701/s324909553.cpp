#include <bits/stdc++.h>
using namespace std;
int main(){
  int N; cin >> N;
  vector<string>S(N);
  set<string>set;
  for (int i=0; i<N; i++){
    cin >> S[i];
  }
  for (int i=0; i<N; i++){
    set.insert(S[i]);
  }
  int ans = set.size();
  cout << ans << endl;
  return 0;
}