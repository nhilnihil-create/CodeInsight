#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> p(m);
  vector<string> s(m);
  for (int i = 0;i < m;i++){
    cin >> p.at(i) >> s.at(i);
  }
  
  vector<int> w(n,0);
  vector<bool> a(n,false);
  
  for (int i = 0;i < m;i++){
    if (s.at(i) == "AC"){
      a.at(p.at(i) - 1) = true;
    }
    if (a.at(p.at(i) - 1) == false && s.at(i) == "WA"){
      w.at(p.at(i) - 1)++;
    }
  }
  
  int ansa = 0;
  int ansb = 0;
  
  for (int i = 0;i < n;i++){
    if (a.at(i)){
      ansa++;
      ansb += w.at(i);
    }
  }
  cout << ansa << " " << ansb << endl;
}