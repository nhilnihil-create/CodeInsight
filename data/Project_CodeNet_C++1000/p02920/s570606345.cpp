#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, N2;
  cin >> N;
  N2 = 1 << N;

  vector<int> S(N2);
  for (int i = 0; i < N2; i++) cin >> S[i];
  sort(S.begin(), S.end());

  vector<int> s;
  s.push_back(S.back());
  S.back() = -1;

  for(int i = 0; i < N; i++){
    vector<int> p = s;
    sort(p.begin(), p.end());
    
    int Si = N2 - 1;
    while (p.size() > 0 && Si >= 0){
      if (S[Si] == -1){
        --Si;
        continue;
      }
      if (S[Si] < p.back()){
        s.push_back(S[Si]);
        p.pop_back();
        S[Si] = -1;
      }
      --Si;
    }
    if (p.size() > 0){
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  return 0;
}