#include <bits/stdc++.h>
using namespace std;;

int main() {
  int N; cin >> N; map<string,int> S;
  for (int i =0; i<N; i++) {
    string s; cin >> s;
    if (!S.count(s)) {
      S[s] = 1;
    } else {
      S.at(s)++;
    }
  }  
  cout << S.size() << endl; 
}
  