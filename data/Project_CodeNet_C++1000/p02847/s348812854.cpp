#include <iostream>
#include <vector>
#include <string>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  vector<string> day{"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
  string s;
  cin >> s;
  int num;
  rep(i, 7){
    if (s == day[i]){
      num = i;
    }
  }
  int ans = 7 - num;
  cout << ans << endl;
  
  return 0;
}