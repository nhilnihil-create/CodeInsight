#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  cin>>s;
  int len=0;
  len = s.size();
 
  for(int i;i<len;i++){
    if(s[i]=='?'){
      s.replace(i, 1, "D");
      
    }
  }
  cout<<s<<endl;

}