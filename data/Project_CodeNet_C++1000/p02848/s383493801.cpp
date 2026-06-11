#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;	cin >> n;
  string s;	cin >> s;
  for(int i=0;i<n;i++){
    for(int j=0;j<s.size();j++){
      if(s[j]=='Z')	s[j]='A';
      else	s[j]=(char)(s[j]+1);
    }
  }
  cout << s;
}