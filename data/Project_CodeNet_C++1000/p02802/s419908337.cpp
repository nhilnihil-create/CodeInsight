#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M;
  vector<pair<int,string>> V(M);
  for (int i = 0; i < M; i++) 
    cin >> V.at(i).first >> V.at(i).second;
  
  vector<int> W(N,0);
  
  int ac = 0; 
  int wa = 0; 
  for (int j = 0; j < M; j++) {
    if (V.at(j).second == "AC")
      W.at(V.at(j).first - 1)++;
    if (W.at(V.at(j).first - 1) == 0 && V.at(j).second == "WA")
      wa++;
  }
  
  for (int l = 0; l < N; l++) {
    if (W.at(l) > 0)
      ac++;
  }
  
  for (int k = 0; k < M; k++) {
    if (W.at(V.at(k).first - 1) == 0 && V.at(k).second == "WA")
      wa--;
  }
  
  cout << ac << " " << wa << endl;
  
  
}
