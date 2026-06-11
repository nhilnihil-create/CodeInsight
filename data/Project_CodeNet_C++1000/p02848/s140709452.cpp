#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string s;
  cin >> n >> s;
  
  int nn = s.length();
  
  for(int i = 0; i < nn; i++){
    int tmp = (int)s[i];
     
    int tt = tmp - 65 + 1;
    
    tt = tt + n;
    
    int ans = tt % 26;
    if(ans == 0) ans = 26;
    s[i] = char(ans + 65 - 1);
  }
  for(int i = 0; i < nn; i++){
    cout <<s[i];
  }
    }
