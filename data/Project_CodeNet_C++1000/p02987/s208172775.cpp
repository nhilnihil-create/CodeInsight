#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  vector<char> s(4);
  int i;
  for(i=0;i<4;i++) cin >> s[i];
  sort(s.begin(),s.end());
  if(s[0]==s[1]&&s[1]!=s[2]&&s[2]==s[3]) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}