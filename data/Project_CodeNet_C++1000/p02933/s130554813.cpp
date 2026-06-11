#include <iostream>
#include <string>
using namespace std;

int main(){
  int num;
  string s;
  
  cin >> num >> s;
  if(num >= 3200){
  	cout << s;
  }else{
  	cout << "red";
  }
  return 0;
}