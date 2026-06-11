#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n;
  string s;
  cin >> n >> s;
  int total = 0;
  for(int i = 0; i < n - 2; i++){
    int j = i + 1;
    int k = i + 2;
    if(s.at(i) == 'A' && s.at(j) == 'B' && s.at(k) == 'C') total++;
  }
  
  cout << total << endl;
 
  
  
}

