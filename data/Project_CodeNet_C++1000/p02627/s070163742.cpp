#include<iostream>
using namespace std;

#include <ctype.h>
int main(){
  char c; cin >> c;
  if (isupper(c)) c = 'A';
  else c = 'a';
  cout << c << endl;
}