#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  string s;

  cin >> s;
  
  int S = 0;

  for(int i=0;i<s.length();i++){
      S = (S+(int)(s[i]-'0'))%9;
  }
  
  if(S==0){
      printf("Yes\n");
  }else{
      printf("No\n");
  }

  return 0;
}