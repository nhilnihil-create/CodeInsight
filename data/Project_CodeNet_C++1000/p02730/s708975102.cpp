#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  bool f = true;
  int n = s.size();
  for(int i = 0; i < n / 2; ++i){
    if(s[i] != s[n - 1 - i]) f = false;
  }
  for(int i = 0; i < n / 2 / 2; ++i){
    if(s[i] != s[n / 2 - 1 - i]) f = false;
    if(s[n / 2 + 1 + i] != s[n - 1 - i]) f = false;
  }
  cout << (f ? "Yes" : "No") << endl;
}