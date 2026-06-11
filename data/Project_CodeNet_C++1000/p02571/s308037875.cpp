#include <bits/stdc++.h>
using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  int s = S.size();
  int t = T.size();

  int min_count = 1000;
  for (int i = 0; i <= s - t; i++) {
    int count = 0;
    for (int j = 0; j < t; j++) {
     
      if (S.at(i + j) != T.at(j)) count++;
      
    }
     min_count = min(min_count, count);
  }
  
  cout << min_count << endl;
}
  