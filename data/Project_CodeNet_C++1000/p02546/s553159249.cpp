#include<iostream>
using namespace std;

int main(){
  string str;
  cin >> str;
  
  if(str[str.length()-1] == 's'){
    cout << str << "es" << endl;
  }else{
    cout << str << "s" << endl;
  }
  
  return 0;
}