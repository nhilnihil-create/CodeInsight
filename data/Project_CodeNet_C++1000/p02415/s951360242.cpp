// 1_8_A
#include <iostream>
using namespace std;

string swap_case(string str){
  for(int i = 0; i < (int)str.size(); i++){
    if('a' <= str[i] && str[i] <= 'z'){
      str[i] = str[i] - ('a' - 'A');
    } else if('A' <= str[i] && str[i] <= 'Z'){
      str[i] = str[i] + ('a' - 'A');
    }
  }
  return str;
}

int main(){
  string str;
  getline(cin, str);
  cout << swap_case(str) << endl;
  return 0;
}