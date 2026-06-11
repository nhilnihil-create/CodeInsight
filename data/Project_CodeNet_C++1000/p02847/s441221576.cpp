#include <bits/stdc++.h>
using namespace std;

int main(){
  string day;
  cin >> day;
  vector<string> days(7);
  days.at(0) = "SUN";
  days.at(1) = "MON";
  days.at(2) = "TUE";
  days.at(3) = "WED";
  days.at(4) = "THU";
  days.at(5) = "FRI";
  days.at(6) = "SAT";
  int ans = 0;
  
  for(int i = 0; i < 7; i++){
    if(day == days.at(i)){
      ans = 7 - i;
    }
  }
  cout << ans << endl;
}