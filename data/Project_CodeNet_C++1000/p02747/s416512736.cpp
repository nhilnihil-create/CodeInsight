#include <string>
#include <iostream>
using namespace std;

int main() {
  string str;
  cin >> str;
  
  bool hFlag = false;
  bool iFlag = false;
  int count = 0;
  for(int i=0; i < str.length(); i++){
    if(count == 0 && str[i] == 'h'){
      hFlag = true;
      iFlag = false;
      count++;
    } else if(count == 1 && str[i] == 'i'){
      iFlag = true;
      count = 0;
    } else {
      hFlag = false;
      iFlag = false;
      break;
    }  
  }
  
  if (hFlag && iFlag) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  

  return 0;
}