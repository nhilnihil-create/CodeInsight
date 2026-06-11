#include<bits/stdc++.h>
using namespace std;
int main(){
  char c;
  set<char> s;
  for(int i = 0;i < 4;i++){
    cin >> c;
    s.insert(c);
  }
  if(s.size() == 2)cout << "Yes" << endl;
  else cout << "No" << endl;
}