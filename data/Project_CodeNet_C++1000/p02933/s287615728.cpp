#include<bits/stdc++.h>
using namespace std;

int main() {
  int a;
  string s, answer;
  cin >> a >> s;
  
  if(a < 3200) answer = "red";
  else answer = s;
  
  cout << answer << endl;
}