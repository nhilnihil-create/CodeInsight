#include <bits/stdc++.h>
using namespace std;
string hitachi;
string verif ="";
int main() {
  cin >> hitachi;
  bool ans = false;
  for(int i = 0;i<(hitachi.size() / 2);i++){
    verif += "hi";
    if(verif == hitachi){
      ans = true;
    }
  }
  cout<<(ans? "Yes":"No") << endl;
  return 0;
}
