#include <iostream>
#include <string>


using namespace std;

int main(){
  int n;
  string s;
  cin >> n >>s;
  for(int i = 0; i < s.size()+1; i++){
    for(int j = 0; j < n; j++) {
      if(s[i] == 'Z') {
        s[i] = 'A';
      } else {
        s[i] = s[i] + 1;
      }
    }
  }
  cout << s << endl;
  return 0;
}
