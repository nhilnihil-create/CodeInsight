#include <iostream>
#include <string>

using namespace std;

int main() {

  string inp;
  cin >> inp;
  for(int i = 0;i < inp.size();i++){
    if(i % 2 == 1 && inp[i] == 'R'){
      cout << "No";
      return 0;
    }else if(i % 2 == 0 && inp[i] == 'L'){
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}
