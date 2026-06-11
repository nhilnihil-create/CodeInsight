#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string s, t;
  cin >> s >> t;
  
  for(int i = 0; i < N; i++){
   cout << s.at(i) << t.at(i);
  }
  
  cout << endl;
}
