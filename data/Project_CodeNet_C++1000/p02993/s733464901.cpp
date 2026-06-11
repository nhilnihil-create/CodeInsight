#include <iostream>
using namespace std;
int main(){
  string s;    
  cin >> s;
  int i;
  for(i=0;i<4;i++){    
    if(s[i]==s[i+1]){   
      cout << "Bad" << "\n";     
      return 0;
    }
  }
  cout << "Good" << "\n";
  return 0;
}