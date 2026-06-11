#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;

int main(){
  string s, t;
  int cnt = 0;
  cin >> s >> t;
  for (int i = 0; i < s.size(); i++){
    if (!(s[i] == t[i])){
      s[i] = t[i];
      cnt++;
    }
  }
  cout << cnt << endl;
}