#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int D;
  vector<pair<int, int>> c(26);
  vector<vector<int>> s(D, vector<int>(26));
  vector<int> t(D);
  
  cin >> D;
  for(int i = 0; i < 26; i++){
    cin >> c.at(i).first;
    c.at(i).second = 0;
  }
  
  for(int i = 0; i < D; i++){
    for(int j = 0; j < 26; j++){
      cin >> s.at(i).at(j);
    }
  }
  
  cout << endl;
  for(int i = 0; i < D; i++){
    cin >> t.at(i);
  }
  
  int Pl = 0;
  int Mi = 0;
  for(int i = 0; i < D; i++){
    Pl += s.at(i).at(t.at(i)-1);
    c.at(t.at(i)-1).second = i + 1;
      for(int j = 0; j < 26; j++){
        Mi += c.at(j).first*(i+1 - c.at(j).second);
      }
    Pl -= Mi;
    Mi = 0;
    cout << Pl << endl;
  }    
}
