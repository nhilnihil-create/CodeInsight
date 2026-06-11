#include <bits/stdc++.h>
using namespace std;

int main(void){
    
  string s;
  cin >> s;
  int len = s.size();
  int N = s.size() / 2;
  int ans = 0;
  
  for(int i=0;i<N;i++){
      if(s[i] != s[len-i-1]) ans++;
  }
  cout << ans << endl;
  
}
