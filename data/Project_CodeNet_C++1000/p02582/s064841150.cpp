#include <bits/stdc++.h>
using namespace std;
 
int main() {

  string s;
  cin >> s;

  s.append("S");
  
  int Srainy = 0;
  int Nrainy = 0;

  for (int i=0;i<s.length();i++){
      
    if(s[i]=='R'){
      Nrainy++;    
    }else{
      Srainy=max(Nrainy, Srainy);
      Nrainy=0;
    }
  }

  printf("%d\n", Srainy);

  return 0;
}