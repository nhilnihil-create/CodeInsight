#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const string button[10] ={
  "0", ".,!? ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int main(){
  int T;
  cin >> T;
  while(T--){
    string ans = "";
    string s;
    cin >> s;
    
    int tmp;
    for(int i = 0 ; i < s.size() ;i++){
      int cnt = 0;
      tmp = s[i]-'0';
      if(tmp == 0) continue;
      while(1){
	if(s[i] != s[i+1]) break;
	cnt++, i++;
	if(button[tmp].size() == cnt) cnt = 0;
      }
      ans += button[tmp][cnt];
    }
    cout << ans << endl;
  }
  return 0;
}

	