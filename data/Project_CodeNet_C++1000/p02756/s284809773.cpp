#include <bits/stdc++.h>
using namespace std;

int main() {
  deque<char> S;
  string s;
  cin >> s;
  for(int i = 0;i < s.size();i++){
    S.push_back(s[i]);
  }
  int Q;
  cin >> Q;
  bool rev = false;
  for(int i = 0; i < Q;i++){
    int q;
    cin >> q;
    if(q == 1){
      if(rev){
        rev = false;
      }
      else{
        rev = true;
      }
    }
    else{
      int F;
      char C;
      cin >> F >> C;
      if(F == 1){
        if(rev == false){
          S.push_front(C);
        }
        else{
          S.push_back(C);
        }
      }
      else{
        if(rev == false){
          S.push_back(C);
        }
        else{
          S.push_front(C);
        }
      }
    }
  }
  if(!rev){
    for(int i = 0;i < S.size();i++){
      cout << S[i];
    }
  }
  else{
    for(int i =  S.size() -1;i >= 0;i--){
      cout <<S[i];
    }
  }
  cout << endl;
}