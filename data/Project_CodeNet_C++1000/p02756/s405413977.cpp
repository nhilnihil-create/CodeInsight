#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string S; int Q; cin >> S >> Q;
  
  int countOne = 0;
  
  deque<char> frontDeque, backDeque;
  
  for (int i = 0; i < Q; i++) {
    
    int T; cin >> T;
    
    if (T == 1) countOne++;
    
    if (T == 2) {
      
      int F; char C; cin >> F >> C;
      
      if (F == 1) {
        if (countOne % 2 == 0) frontDeque.push_back(C);
        if (countOne % 2 == 1) backDeque.push_back(C);
      }
      
      if (F == 2) {
        if (countOne % 2 == 0) backDeque.push_back(C);
        if (countOne % 2 == 1) frontDeque.push_back(C);
      }
      
    }
    
  }
  
  if (countOne % 2 == 0) {
    for (int i = frontDeque.size() - 1; 0 <= i; i--) cout << frontDeque.at(i);
    cout << S;
    for (int i = 0; i < backDeque.size(); i++) cout << backDeque.at(i);
  }
  
  if (countOne % 2 == 1) {
    for (int i = backDeque.size() - 1; 0 <= i; i--) cout << backDeque.at(i);
    reverse(S.begin(), S.end());
    cout << S;
    for (int i = 0; i < frontDeque.size(); i++) cout << frontDeque.at(i);
  }
  
  cout << endl;
  
}