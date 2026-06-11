#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> ac_count(N, 0);
  
  int W = 0, A = 0, a;
  string s;
  for (int i = 0; i < M; i++) {
    cin >> a >> s;
    
    if (ac_count.at(a - 1) == -1) continue;
    
    if (s == "AC") {
      W += ac_count.at(a - 1);
      ac_count.at(a - 1) = -1;
      A++;
    }
    
    else ac_count.at(a - 1)++;
    
  }
  
  cout << A << ' ' << W << endl;
  
}
