#include <bits/stdc++.h>
using namespace std;

int main(){
  string s; cin >> s;
  int flag = 1;
  for(int i=0; i<3; i++){
    if(s[i]==s[i+1]) flag = 0;
  }
  cout << (flag?"Good":"Bad") << endl;
}