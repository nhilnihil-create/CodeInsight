#include <iostream>
using namespace std;
int main(){
  string s;
  cin >> s;
  int i;
  for(i=0;i<s.size();i++){
    if((i+1)%2==1&&s[i]!='R'&&s[i]!='U'&&s[i]!='D'){
      cout << "No" << "\n";
      return 0;
    }
  }
  for(i=0;i<s.size();i++){
    if((i+1)%2==0&&s[i]!='L'&&s[i]!='U'&&s[i]!='D'){
      cout << "No" << "\n";
      return 0;
    }
  }
  cout << "Yes" << "\n";
  return 0;
}