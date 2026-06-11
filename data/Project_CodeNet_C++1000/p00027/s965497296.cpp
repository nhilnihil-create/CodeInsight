#include <iostream>
using namespace std;
const string str[] = {"Wednesday","Thursday","Friday",
		      "Saturday","Sunday","Monday","Tuesday"};
const int m[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
int main(){
  int mon,day;
  while(cin >> mon >> day, mon + day){

    for(int i = 0 ; i < mon ; i++){
      day += m[i];
    }
    cout << str[day%7] << endl;
}
  return 0;
}