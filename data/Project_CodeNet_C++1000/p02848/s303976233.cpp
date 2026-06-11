#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  string s;
  cin >> n >> s;
  string ans="";
  for(int i=0;i<s.size();i++){
    ans+=char((s.at(i)+n-65)%26+65);
//    cout << (s.at(i)+n-65)%26+65 << '/';
  }
  cout << ans << endl;
  return 0;
}