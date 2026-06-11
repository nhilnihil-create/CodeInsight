#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
using namespace std;

int main(){
  int n, l, c, s;
  string str, ans;
  map<int, string> m;
  m[1] = ".,!? ";
  m[2] = "abc";
  m[3] = "def";
  m[4] = "ghi";
  m[5] = "jkl";
  m[6] = "mno";
  m[7] = "pqrs";
  m[8] = "tuv";
  m[9] = "wxyz";
  cin >> n;
  for (int i = 0; i < n; ++i){
    cin >> str;
    c = 0;
    l = str.length();
    ans = "";
    s = 0;
    for (int j = 0; j < l; ++j){
      int S = str[j] - 48;
      if (s == S) c++;
      else  if (S == 0){
	c %= m[s].length();
	ans += m[s][c];
	c = -1;
	s = S;
      }else{
	s = S;
	c = 0;
      }
    }
    cout << ans << endl;
  }
  return 0;
}