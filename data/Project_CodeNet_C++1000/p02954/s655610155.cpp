#include <iostream>
#include <vector>
#include <string>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  vector<int> num, point;
  int now = 0;
  char d = 'R';
  rep(i, n){
    if (s[i] == d) now++;
    else {
      num.push_back(now);
      if (d == 'R') point.push_back(i-1);
      d = s[i];
      now = 1;
    }
  }
  num.push_back(now);
  point.push_back(-1);
  
  int x = 0;
  rep(i, n){
    if (i != point[x]) cout << 0;
    else{
      int a = (num[x*2] + 1) / 2 + num[x*2+1] / 2;
      int b = num[x*2] / 2 + (num[x*2+1] + 1) / 2;
      cout << a << ' ' << b;
      x++;
      i++;
    }
    if (i == n-1) cout << endl;
    else cout << ' ';
  }
  
  return 0;
}