#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int countR = 0;
  int countW = 0;
  for(int i = 0;i < n;i++){
    if(s.at(i) == 'R') countR++;
    else countW++;
  }
  int count = 0;
  for(int i = 0;i < countR;i++){
    if(s.at(i) == 'W') count++;
  }
  cout << count << endl;
}
