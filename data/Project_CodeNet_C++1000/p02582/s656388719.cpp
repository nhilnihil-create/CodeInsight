#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int cnt = 0;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == 'R'){
     	cnt++; 
    }
  }
  
  if(cnt == 2 && s[1] == 'S'){
    cnt = 1;
  }
  cout << cnt << endl;
}