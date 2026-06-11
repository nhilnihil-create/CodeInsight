#include <bits/stdc++.h>
using namespace std;

string rev(string s){
  reverse(s.begin(), s.end());
  return s;
}

int main(void){
  int n; cin >> n;
  while(n--){
    string str; cin >> str;
    set < string > abcd;
    for(int i=1; i < str.length(); i++){
      string str1, str2;
      str1 = str.substr(0, i);
      str2 = str.substr(i, str.length()-i);
      abcd.insert(str1+str2);
      abcd.insert(str2+str1);
      abcd.insert(rev(str1)+str2);
      abcd.insert(str1+rev(str2));
      abcd.insert(rev(str2)+str1);
      abcd.insert(str2+rev(str1));
      abcd.insert(rev(str2)+rev(str1));
      abcd.insert(rev(str1)+rev(str2));
    }
    cout << abcd.size() << endl;
  }
  return 0;
}