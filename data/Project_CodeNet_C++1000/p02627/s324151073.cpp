#include<bits/stdc++.h>
using namespace std;

int main(){
  string s = "QWERTYUIOPASDFGHJKLZXCVBNM";
  char c;
  cin >> c;
  string ans = "a";
 for(int i = 0; i < s.size(); i++){
   if(c == s[i]) {ans = "A"; break;}
 }
 cout << ans << endl;
}