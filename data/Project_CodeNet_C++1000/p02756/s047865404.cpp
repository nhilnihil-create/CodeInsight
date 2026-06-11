#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  string S;
  cin >> S;
  long long Q;
  cin >> Q;
  bool reverse_ = false;
  string before = "", after = "";
  for (int i = 0; i < Q; i++){
    long long T;
    cin >> T;
    if (T == 1){
      if (reverse_ == false) reverse_ = true;
      else reverse_ = false;
    }
    else {
      long long F;
      cin >> F;
      string C;
      cin >> C;
      if (reverse_ == false && F == 1) before += C;
      if (reverse_ == true && F == 1) after += C;
      if (reverse_ == false && F == 2) after += C;
      if (reverse_ == true && F == 2) before += C;
    }
  }
  reverse(before.begin(), before.end());
  S = before + S + after;
  if (reverse_ == true) reverse(S.begin(), S.end());
  cout << S << endl;
}