#include <iostream>
#include <string>
using namespace std;

int main(void){
  int result;
  string s;
  cin >> s;
  if(s=="SUN") result=7;
  else if(s=="MON") result=6;
  else if(s=="TUE") result=5;
  else if(s=="WED") result=4;
  else if(s=="THU") result=3;
  else if(s=="FRI") result=2;
  else result=1;

  cout << result << endl;
  return 0;
}