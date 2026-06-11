#include <iostream>
using namespace std;
int main(){
  int i,ans=0;
  char s[5],t[5];
  for (i=1;i<=3;i++){
    cin >> s[i];
  }
  for (i=1;i<=3;i++){
    cin >> t[i];
  }
  for (i=1;i<=3;i++){
    if (s[i]==t[i]) ans++;
  }
  cout << ans << endl;
}