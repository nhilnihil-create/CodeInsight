#include <iostream>
using namespace std;
int main(){
  char str[4] ;
  int i1 ;
  cin >> str ;
  if ( str[0] == str [1] ){
    i1++;
  }
  if ( str[0] == str [2] ){
    i1++;
  }
  if ( str[0] == str [3] ){
    i1++;
  }
  if ( str[1] == str [2] ){
    i1++;
  }
  if ( str[1] == str [3] ){
    i1++;
  }
  if ( str[2] == str [3] ){
    i1++;
  }
  if ( i1 == 2 ){
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  return 0;
}
  
