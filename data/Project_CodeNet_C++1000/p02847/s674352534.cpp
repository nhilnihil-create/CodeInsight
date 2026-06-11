#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
  string s; cin >> s;
  vector<string> week = vector<string>{"SUN","MON","TUE","WED","THU","FRI","SAT"};
  int index = 0;
  for(int i=0; i<week.size(); i++){
    if(s == week[i]){
      index = i;
      break;
    }
  }
  cout << 7-index << endl;
}