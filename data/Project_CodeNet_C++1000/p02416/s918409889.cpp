#include <iostream>
#include <cstdlib>

using namespace std;

int main(void) {
  string number;
  int answer = 0;
  while(cin >> number && number[0] != '0') {
    for(int i = 0; i < number.length(); i++) {
      answer += number[i] - '0';
    }
    cout << answer << endl;
    answer = 0;
  }
  return 0;
}