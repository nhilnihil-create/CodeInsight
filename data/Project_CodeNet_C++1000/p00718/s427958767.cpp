#include <iostream>
#include <string>
using namespace std;


bool isNumber(char c) {
  if(c >= '0' && c <= '9') return true;
  else                     return false;
}

int ctoi(char c) {
  return c-'0';
}

char itoc(int i) {
  return '0'+i;
}

int toInt(string s) {
  int ans = 0;
  int tmp = 1;
  for(int i = 0; i < s.length(); i++) {
    if(isNumber(s[i])) {
      tmp = ctoi(s[i]);
    } else {
      switch(s[i]) {
      case 'm': ans += tmp * 1000; break;
      case 'c': ans += tmp * 100;  break;
      case 'x': ans += tmp * 10;   break;
      case 'i': ans += tmp;        break;
      }
      tmp = 1;
    }
  }
  return ans;
}

string toMcxi(int x) {
  string ans = "";
  for(int i = 1000; i >= 1; i /= 10) {
    int tmp = x / i;
    if(tmp == 0) continue;
    if(tmp != 1) ans += itoc(tmp);
    switch(i) {
    case 1000: ans += 'm'; break;
    case 100:  ans += 'c'; break;
    case 10:   ans += 'x'; break;
    case 1:    ans += 'i'; break;
    }
    x %= i;
  }
  return ans;
}

main() {
  int N;
  string s1, s2;
  cin >> N;
  for(int t = 0; t < N; t++) {
    cin >> s1 >> s2;
    cout << toMcxi(toInt(s1)+toInt(s2)) << endl;
  }
}