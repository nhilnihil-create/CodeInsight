#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  int count=0;
  cin>>s;
  
  for (int i;i<s.size()/2;i++) {
    if (s[i]==s[s.size()-1-i]) {
      continue;
    }
    else {
      count+=1;
    }
  }
  cout<<count<<endl;
}
      
      
      