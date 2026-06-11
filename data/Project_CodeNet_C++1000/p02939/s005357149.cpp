#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;
  char tempc = '0';
  int count = 0;
  int length = S.length();
  for(int i = 0; i < length; i++) {
    if(tempc == S[i]) {
      if((i + 1) < length) {
        tempc = '0';
        i++;
        count++;
      }
    } else {
      tempc = S[i];
      count++;
    }
  }
  cout << count << endl;
  return 0;
}
