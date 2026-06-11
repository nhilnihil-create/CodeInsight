#include <bits/stdc++.h>
using namespace std;

int main(){
  string i;
  cin >> i;
  bool ans = true;
  if(i[2]!=i[3])ans =false;
  if(i[4]!=i[5])ans =false;
  cout << (ans?"Yes":"No") << endl;
  return 0;
}
