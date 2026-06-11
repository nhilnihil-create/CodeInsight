#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M; cin >> N >> M;
  vector<int> p(M); vector<string> S(M);
  for (int i =0; i<M; i++) cin >> p.at(i) >> S.at(i);
  
  vector<int> count(N,0);
  for (int i =M-1; i>=0; i--) {
    if (S.at(i) == "AC") {
      count.at(p.at(i)-1) =1;
    } else if(S.at(i) == "WA" && count.at(p.at(i)-1) != 0) {
      count.at(p.at(i)-1)++;
    }
  }
  
  int correct =0, penalty =0;
  for (int i =0; i<N; i++) {
    if (count.at(i) != 0) {
      penalty += count.at(i) -1;
      correct++;
    }
  }
  cout << correct << " " << penalty << endl;
}