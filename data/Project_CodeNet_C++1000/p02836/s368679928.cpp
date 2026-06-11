#include <iostream>
using namespace std;
int main(){
  string s;
  cin >> s;
  int cnt = 0;
  int i;
  for(i=0;i<=(s.size()-1)/2;i++){
    if(s[i]!=s[s.size()-1-i]) cnt++;
  }
  cout << cnt << "\n";
  return 0;
}