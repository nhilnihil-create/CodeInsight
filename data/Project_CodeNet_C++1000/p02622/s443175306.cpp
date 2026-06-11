#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string s, t;
  cin >> s >> t;
  int total = 0;
  
  int size = s.size();
  
  for (int i = 0; i < size; i++){
    if(s.at(i) != t.at(i)){
      total = total + 1;
    }
  }
  
  cout << total << endl;
}

