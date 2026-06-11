#include <iostream>
using namespace std;   
int main(){
  string s,t;
  cin >> s >> t;
  int cnt = 0;
  int i;                                                          
  for(i=0;i<3;i++){
    if(s[i]==t[i]) cnt++;                    
  }
  cout << cnt << "\n";
  return 0;
}