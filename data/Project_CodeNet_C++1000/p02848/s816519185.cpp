#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  string s; cin >> s;
  for(int i = 0; i < s.size(); i++){
    char a = s.at(i);
    if(char(a + n) <= 'Z')
      cout << char(a+n);
    else
      cout << char(a+n-26);
  }
}