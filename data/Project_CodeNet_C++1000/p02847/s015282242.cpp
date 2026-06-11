#include<bits/stdc++.h>
using namespace std;

int main(void){
  string S;
  int tmp, delta;
  string day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
  cin >> S;
  for(int i = 0; i < 7; i++){
    if(S == day[i]){
      tmp = i;
      break;
    }
  }
  delta = 7 - tmp;
  cout << delta << "\n";
  return 0;
}
